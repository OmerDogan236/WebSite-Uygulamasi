#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

int main() {
    // Platform ve cihaz bilgilerini almak için gerekli değişkenler
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;

    // Platform bilgilerini al
    clGetPlatformIDs(1, &platform_id, &ret_num_platforms);

    // Cihaz bilgilerini al
    clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

    // OpenCL bağlantısını oluştur
    cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, NULL);

    // Komut kuyruğunu oluştur
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, NULL);

    // OpenCL kernel kodu
    const char *source_str = "__kernel void sum(__global const int *a, __global const int *b, __global int *c) {"
                             "    int i = get_global_id(0);"
                             "    c[i] = a[i] + b[i];"
                             "}";

    // OpenCL programını oluştur
    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, NULL, NULL);

    // Programı derle
    clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

    // OpenCL kernel fonksiyonunu al
    cl_kernel kernel = clCreateKernel(program, "sum", NULL);

    // Verileri hazırla
    int N = 10;
    int *a = (int *)malloc(sizeof(int) * N);
    int *b = (int *)malloc(sizeof(int) * N);
    int *c = (int *)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i;
    }

    // OpenCL bellek nesnelerini oluştur
    cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * N, NULL, NULL);
    cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * N, NULL, NULL);
    cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, sizeof(int) * N, NULL, NULL);

    // Verileri belleğe kopyala
    clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, sizeof(int) * N, a, 0, NULL, NULL);
    clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, sizeof(int) * N, b, 0, NULL, NULL);

    // Kernel argümanlarını ayarla
    clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&a_mem_obj);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&b_mem_obj);
    clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&c_mem_obj);

    // Kernel'i çalıştır
    size_t global_item_size = N;
    size_t local_item_size = 1;
    clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

    // Sonucu bellekten oku
    clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0, sizeof(int) * N, c, 0, NULL, NULL);

    // Sonucu yazdır
    for (int i = 0; i < N; i++) {
        printf("%d + %d = %d\n", a[i], b[i], c[i]);
    }

    // Bellek nesnelerini serbest bırak
    clReleaseMemObject(a_mem_obj);
    clReleaseMemObject(b_mem_obj);
    clReleaseMemObject(c_mem_obj);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(command_queue);
    clReleaseContext(context);

    // Belleği serbest bırak
    free(a);
    free(b);
    free(c);

    return 0;
}


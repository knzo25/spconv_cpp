
cmake_minimum_required(VERSION 3.20)
add_library(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel OBJECT ConvKernel_conv_kernel.cu)
# set_target_properties(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties( spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PROPERTIES CXX_STANDARD 14 CUDA_STANDARD 14)

# set_target_properties(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
# set_target_properties(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PROPERTIES CUDA_RESOLVE_DEVICE_SYMBOLS ON)

target_include_directories(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PRIVATE
    /usr/local/cuda/include)
target_compile_options(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PRIVATE $<$<COMPILE_LANGUAGE:CUDA>:
     -DTV_CUDA
    -gencode=arch=compute_75,code=sm_75
    -gencode=arch=compute_80,code=sm_80
    -gencode=arch=compute_86,code=sm_86
    -gencode=arch=compute_89,code=sm_89
    -Xcudafe "--diag_suppress=implicit_return_from_non_void_function"
    --expt-relaxed-constexpr
    -Xcompiler="-fPIC"
    -Xcompiler='-O3'>)
target_compile_options(spconvlib_cumm_conv_main_Turing_s8s8s8s32f32tnt_m256n128k64m128n64k64A1T8816_200_C301LLL_SK_S8_ConvKernel PRIVATE $<$<COMPILE_LANGUAGE:CXX>: 
    -O3
    -fPIC>)

                
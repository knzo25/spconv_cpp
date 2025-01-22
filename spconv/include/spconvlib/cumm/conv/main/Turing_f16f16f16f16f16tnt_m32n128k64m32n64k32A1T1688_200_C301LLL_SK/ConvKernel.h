#pragma once
#include <spconvlib/cumm/common/TensorViewNVRTCKernel.h>
#include <spconvlib/cumm/gemm/layout/RowMajor.h>
#include <spconvlib/cumm/gemm/layout/ColumnMajor.h>
#include <spconvlib/cumm/common/GemmBasicKernel.h>
#include <spconvlib/cumm/common/GemmBasic.h>
#include <spconvlib/cumm/common/GemmKernelFlags.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/inpitera/ForwardDgradSparseIOIterator.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/inpiterb/WeightIteratorDP4A.h>
#include <spconvlib/cumm/conv/main/cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/la/TensorGeneric.h>
#include <spconvlib/cumm/conv/main/cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/lb/TensorGeneric.h>
#include <spconvlib/cumm/conv/main/cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/lc/TensorGeneric.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/gemm_smem_storage/BlockMmaStorage.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/out_smem_storage/OutputSmemStorage.h>
#include <spconvlib/cumm/conv/main/cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/ConvParams.h>
#include <spconvlib/cumm/conv/main/cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/cp/ConvProblem.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/out_iter/OutIterator.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/out_iter_const/OutIterator.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/out_op/LinearCombination.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/mma/Mma.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/mma_miterd/MaskIGemmIteratorMaskLoaderDynamic.h>
#include <spconvlib/cumm/conv/main/Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK/output/Output.h>
namespace spconvlib {
namespace cumm {
namespace conv {
namespace main {
namespace Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK {
using TensorViewNVRTCKernel = spconvlib::cumm::common::TensorViewNVRTCKernel;
using RowMajor = spconvlib::cumm::gemm::layout::RowMajor;
using ColumnMajor = spconvlib::cumm::gemm::layout::ColumnMajor;
using GemmBasicKernel = spconvlib::cumm::common::GemmBasicKernel;
using GemmBasic = spconvlib::cumm::common::GemmBasic;
using GemmKernelFlags = spconvlib::cumm::common::GemmKernelFlags;
using InputIteratorA = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::inpitera::ForwardDgradSparseIOIterator;
using InputIteratorB = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::inpiterb::WeightIteratorDP4A;
using LayoutA = spconvlib::cumm::conv::main::cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::la::TensorGeneric;
using LayoutB = spconvlib::cumm::conv::main::cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::lb::TensorGeneric;
using LayoutC = spconvlib::cumm::conv::main::cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::lc::TensorGeneric;
using BlockMmaStorage = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::gemm_smem_storage::BlockMmaStorage;
using OutputSmemStorage = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::out_smem_storage::OutputSmemStorage;
using ConvParams = spconvlib::cumm::conv::main::cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::ConvParams;
using ConvProblem = spconvlib::cumm::conv::main::cpTuring_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::cp::ConvProblem;
using OutIter = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::out_iter::OutIterator;
using ConstOutIter = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::out_iter_const::OutIterator;
using OutputOp = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::out_op::LinearCombination;
using Mma = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::mma::Mma;
using MaskIGemmIteratorDynamic = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::mma_miterd::MaskIGemmIteratorMaskLoaderDynamic;
using Output = spconvlib::cumm::conv::main::Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK::output::Output;
/**
 * @param params 
 */
__global__ void conv_kernel(ConvParams params);
struct ConvKernel {
};
} // namespace Turing_f16f16f16f16f16tnt_m32n128k64m32n64k32A1T1688_200_C301LLL_SK
} // namespace main
} // namespace conv
} // namespace cumm
} // namespace spconvlib
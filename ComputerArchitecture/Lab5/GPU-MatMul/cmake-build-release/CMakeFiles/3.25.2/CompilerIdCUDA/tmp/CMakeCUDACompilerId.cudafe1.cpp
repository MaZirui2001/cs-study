#pragma section("__nv_managed_data__")
static char __nv_inited_managed_rt = 0; static void **__nv_fatbinhandle_for_managed_rt; static void __nv_save_fatbinhandle_for_managed_rt(void **in){__nv_fatbinhandle_for_managed_rt = in;} static char __nv_init_managed_rt_with_module(void **); static inline void __nv_init_managed_rt(void) { __nv_inited_managed_rt = (__nv_inited_managed_rt ? __nv_inited_managed_rt                 : __nv_init_managed_rt_with_module(__nv_fatbinhandle_for_managed_rt));}
#line 1 "CMakeCUDACompilerId.cu"
#define __nv_is_extended_device_lambda_closure_type(X) false
#define __nv_is_extended_host_device_lambda_closure_type(X) false
#if defined(__nv_is_extended_device_lambda_closure_type) && defined(__nv_is_extended_host_device_lambda_closure_type)
#endif

#line 1
#line 67 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
#pragma warning(push)
#pragma warning(disable: 4820)
#line 708 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\sal.h"
#pragma region Input Buffer SAL 1 compatibility macros
#line 1472
#pragma endregion Input Buffer SAL 1 compatibility macros
#line 2361 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\sal.h"
extern "C" {
#line 2971 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\sal.h"
}
#line 22 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\concurrencysal.h"
extern "C" {
#line 391 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\concurrencysal.h"
}
#line 15 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
#pragma pack ( push, 8 )
#line 47 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 51
extern "C" {
#line 61 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
typedef unsigned __int64 uintptr_t; 
#line 72 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
typedef char *va_list; 
#line 155 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
void __cdecl __va_start(va_list *, ...); 
#line 167 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
}
#line 171 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
extern "C++" {
#line 173
template< class _Ty> 
#line 174
struct __vcrt_va_list_is_reference { 
#line 176
enum: bool { __the_value}; 
#line 177
}; 
#line 179
template< class _Ty> 
#line 180
struct __vcrt_va_list_is_reference< _Ty &>  { 
#line 182
enum: bool { __the_value = '\001'}; 
#line 183
}; 
#line 185
template< class _Ty> 
#line 186
struct __vcrt_va_list_is_reference< _Ty &&>  { 
#line 188
enum: bool { __the_value = '\001'}; 
#line 189
}; 
#line 191
template< class _Ty> 
#line 192
struct __vcrt_assert_va_start_is_not_reference { 
#line 194
static_assert((!__vcrt_va_list_is_reference< _Ty> ::__the_value), "va_start argument must not have reference type and must not be parenthesized");
#line 196
}; 
#line 197
}
#line 207 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vadefs.h"
#pragma warning(pop)
#pragma pack ( pop )
#line 60 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 96 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
__pragma( pack ( push, 8 )) extern "C" {
#line 193 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
typedef unsigned __int64 size_t; 
#if !defined(__CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__)
#define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
#endif
#include "crt/host_runtime.h"
#line 194
typedef __int64 ptrdiff_t; 
#line 195
typedef __int64 intptr_t; 
#line 203 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
typedef bool __vcrt_bool; 
#line 250 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
extern "C++" {
#line 252
template< class _CountofType, size_t _SizeOfArray> char (*__countof_helper(__unaligned _CountofType (& _Array)[_SizeOfArray]))[_SizeOfArray]; 
#line 256
}
#line 377 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
void __cdecl __security_init_cookie(); 
#line 386 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
void __cdecl __security_check_cookie(uintptr_t _StackCookie); 
#line 387
__declspec(noreturn) void __cdecl __report_gsfailure(uintptr_t _StackCookie); 
#line 391 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
extern uintptr_t __security_cookie; 
#line 399 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime.h"
}__pragma( pack ( pop )) 
#line 401
#pragma warning(pop)
#line 121 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 125
__pragma( pack ( push, 8 )) extern "C" {
#line 254 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
extern "C++" {
#line 256
template< bool _Enable, class _Ty> struct _CrtEnableIf; 
#line 259
template< class _Ty> 
#line 260
struct _CrtEnableIf< true, _Ty>  { 
#line 262
typedef _Ty _Type; 
#line 263
}; 
#line 264
}
#line 268 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
typedef bool __crt_bool; 
#line 371 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
void __cdecl _invalid_parameter_noinfo(); 
#line 372
__declspec(noreturn) void __cdecl _invalid_parameter_noinfo_noreturn(); 
#line 374
__declspec(noreturn) void __cdecl 
#line 375
_invoke_watson(const __wchar_t * _Expression, const __wchar_t * _FunctionName, const __wchar_t * _FileName, unsigned _LineNo, uintptr_t _Reserved); 
#line 604 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
typedef int errno_t; 
#line 605
typedef unsigned short wint_t; 
#line 606
typedef unsigned short wctype_t; 
#line 607
typedef long __time32_t; 
#line 608
typedef __int64 __time64_t; 
#line 615
typedef 
#line 610
struct __crt_locale_data_public { 
#line 612
const unsigned short *_locale_pctype; 
#line 613
int _locale_mb_cur_max; 
#line 614
unsigned _locale_lc_codepage; 
#line 615
} __crt_locale_data_public; 
#line 621
typedef 
#line 617
struct __crt_locale_pointers { 
#line 619
struct __crt_locale_data *locinfo; 
#line 620
struct __crt_multibyte_data *mbcinfo; 
#line 621
} __crt_locale_pointers; 
#line 623
typedef __crt_locale_pointers *_locale_t; 
#line 629
typedef 
#line 625
struct _Mbstatet { 
#line 627
unsigned long _Wchar; 
#line 628
unsigned short _Byte, _State; 
#line 629
} _Mbstatet; 
#line 631
typedef _Mbstatet mbstate_t; 
#line 645 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
typedef __time64_t time_t; 
#line 655 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
typedef size_t rsize_t; 
#line 2072 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt.h"
}__pragma( pack ( pop )) 
#line 2075
#pragma warning(pop)
#line 68 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_types.h"
#if 0
#line 68
enum cudaRoundMode { 
#line 70
cudaRoundNearest, 
#line 71
cudaRoundZero, 
#line 72
cudaRoundPosInf, 
#line 73
cudaRoundMinInf
#line 74
}; 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 100
struct char1 { 
#line 102
signed char x; 
#line 103
}; 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 105
struct uchar1 { 
#line 107
unsigned char x; 
#line 108
}; 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 111
struct __declspec(align(2)) char2 { 
#line 113
signed char x, y; 
#line 114
}; 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 116
struct __declspec(align(2)) uchar2 { 
#line 118
unsigned char x, y; 
#line 119
}; 
#endif
#line 121 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 121
struct char3 { 
#line 123
signed char x, y, z; 
#line 124
}; 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 126
struct uchar3 { 
#line 128
unsigned char x, y, z; 
#line 129
}; 
#endif
#line 131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 131
struct __declspec(align(4)) char4 { 
#line 133
signed char x, y, z, w; 
#line 134
}; 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 136
struct __declspec(align(4)) uchar4 { 
#line 138
unsigned char x, y, z, w; 
#line 139
}; 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 141
struct short1 { 
#line 143
short x; 
#line 144
}; 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 146
struct ushort1 { 
#line 148
unsigned short x; 
#line 149
}; 
#endif
#line 151 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 151
struct __declspec(align(4)) short2 { 
#line 153
short x, y; 
#line 154
}; 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 156
struct __declspec(align(4)) ushort2 { 
#line 158
unsigned short x, y; 
#line 159
}; 
#endif
#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 161
struct short3 { 
#line 163
short x, y, z; 
#line 164
}; 
#endif
#line 166 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 166
struct ushort3 { 
#line 168
unsigned short x, y, z; 
#line 169
}; 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 171
struct __declspec(align(8)) short4 { short x; short y; short z; short w; }; 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 172
struct __declspec(align(8)) ushort4 { unsigned short x; unsigned short y; unsigned short z; unsigned short w; }; 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 174
struct int1 { 
#line 176
int x; 
#line 177
}; 
#endif
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 179
struct uint1 { 
#line 181
unsigned x; 
#line 182
}; 
#endif
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 184
struct __declspec(align(8)) int2 { int x; int y; }; 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 185
struct __declspec(align(8)) uint2 { unsigned x; unsigned y; }; 
#endif
#line 187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 187
struct int3 { 
#line 189
int x, y, z; 
#line 190
}; 
#endif
#line 192 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 192
struct uint3 { 
#line 194
unsigned x, y, z; 
#line 195
}; 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 197
struct __declspec(align(16)) int4 { 
#line 199
int x, y, z, w; 
#line 200
}; 
#endif
#line 202 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 202
struct __declspec(align(16)) uint4 { 
#line 204
unsigned x, y, z, w; 
#line 205
}; 
#endif
#line 207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 207
struct long1 { 
#line 209
long x; 
#line 210
}; 
#endif
#line 212 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 212
struct ulong1 { 
#line 214
unsigned long x; 
#line 215
}; 
#endif
#line 218 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 218
struct __declspec(align(8)) long2 { long x; long y; }; 
#endif
#line 219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 219
struct __declspec(align(8)) ulong2 { unsigned long x; unsigned long y; }; 
#endif
#line 234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 234
struct long3 { 
#line 236
long x, y, z; 
#line 237
}; 
#endif
#line 239 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 239
struct ulong3 { 
#line 241
unsigned long x, y, z; 
#line 242
}; 
#endif
#line 244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 244
struct __declspec(align(16)) long4 { 
#line 246
long x, y, z, w; 
#line 247
}; 
#endif
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 249
struct __declspec(align(16)) ulong4 { 
#line 251
unsigned long x, y, z, w; 
#line 252
}; 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 254
struct float1 { 
#line 256
float x; 
#line 257
}; 
#endif
#line 276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 276
struct __declspec(align(8)) float2 { float x; float y; }; 
#endif
#line 281 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 281
struct float3 { 
#line 283
float x, y, z; 
#line 284
}; 
#endif
#line 286 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 286
struct __declspec(align(16)) float4 { 
#line 288
float x, y, z, w; 
#line 289
}; 
#endif
#line 291 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 291
struct longlong1 { 
#line 293
__int64 x; 
#line 294
}; 
#endif
#line 296 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 296
struct ulonglong1 { 
#line 298
unsigned __int64 x; 
#line 299
}; 
#endif
#line 301 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 301
struct __declspec(align(16)) longlong2 { 
#line 303
__int64 x, y; 
#line 304
}; 
#endif
#line 306 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 306
struct __declspec(align(16)) ulonglong2 { 
#line 308
unsigned __int64 x, y; 
#line 309
}; 
#endif
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 311
struct longlong3 { 
#line 313
__int64 x, y, z; 
#line 314
}; 
#endif
#line 316 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 316
struct ulonglong3 { 
#line 318
unsigned __int64 x, y, z; 
#line 319
}; 
#endif
#line 321 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 321
struct __declspec(align(16)) longlong4 { 
#line 323
__int64 x, y, z, w; 
#line 324
}; 
#endif
#line 326 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 326
struct __declspec(align(16)) ulonglong4 { 
#line 328
unsigned __int64 x, y, z, w; 
#line 329
}; 
#endif
#line 331 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 331
struct double1 { 
#line 333
double x; 
#line 334
}; 
#endif
#line 336 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 336
struct __declspec(align(16)) double2 { 
#line 338
double x, y; 
#line 339
}; 
#endif
#line 341 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 341
struct double3 { 
#line 343
double x, y, z; 
#line 344
}; 
#endif
#line 346 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 346
struct __declspec(align(16)) double4 { 
#line 348
double x, y, z, w; 
#line 349
}; 
#endif
#line 363 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef char1 
#line 363
char1; 
#endif
#line 364 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uchar1 
#line 364
uchar1; 
#endif
#line 365 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef char2 
#line 365
char2; 
#endif
#line 366 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uchar2 
#line 366
uchar2; 
#endif
#line 367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef char3 
#line 367
char3; 
#endif
#line 368 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uchar3 
#line 368
uchar3; 
#endif
#line 369 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef char4 
#line 369
char4; 
#endif
#line 370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uchar4 
#line 370
uchar4; 
#endif
#line 371 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef short1 
#line 371
short1; 
#endif
#line 372 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ushort1 
#line 372
ushort1; 
#endif
#line 373 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef short2 
#line 373
short2; 
#endif
#line 374 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ushort2 
#line 374
ushort2; 
#endif
#line 375 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef short3 
#line 375
short3; 
#endif
#line 376 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ushort3 
#line 376
ushort3; 
#endif
#line 377 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef short4 
#line 377
short4; 
#endif
#line 378 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ushort4 
#line 378
ushort4; 
#endif
#line 379 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef int1 
#line 379
int1; 
#endif
#line 380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uint1 
#line 380
uint1; 
#endif
#line 381 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef int2 
#line 381
int2; 
#endif
#line 382 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uint2 
#line 382
uint2; 
#endif
#line 383 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef int3 
#line 383
int3; 
#endif
#line 384 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uint3 
#line 384
uint3; 
#endif
#line 385 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef int4 
#line 385
int4; 
#endif
#line 386 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef uint4 
#line 386
uint4; 
#endif
#line 387 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef long1 
#line 387
long1; 
#endif
#line 388 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulong1 
#line 388
ulong1; 
#endif
#line 389 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef long2 
#line 389
long2; 
#endif
#line 390 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulong2 
#line 390
ulong2; 
#endif
#line 391 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef long3 
#line 391
long3; 
#endif
#line 392 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulong3 
#line 392
ulong3; 
#endif
#line 393 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef long4 
#line 393
long4; 
#endif
#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulong4 
#line 394
ulong4; 
#endif
#line 395 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef float1 
#line 395
float1; 
#endif
#line 396 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef float2 
#line 396
float2; 
#endif
#line 397 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef float3 
#line 397
float3; 
#endif
#line 398 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef float4 
#line 398
float4; 
#endif
#line 399 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef longlong1 
#line 399
longlong1; 
#endif
#line 400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulonglong1 
#line 400
ulonglong1; 
#endif
#line 401 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef longlong2 
#line 401
longlong2; 
#endif
#line 402 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulonglong2 
#line 402
ulonglong2; 
#endif
#line 403 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef longlong3 
#line 403
longlong3; 
#endif
#line 404 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulonglong3 
#line 404
ulonglong3; 
#endif
#line 405 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef longlong4 
#line 405
longlong4; 
#endif
#line 406 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef ulonglong4 
#line 406
ulonglong4; 
#endif
#line 407 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef double1 
#line 407
double1; 
#endif
#line 408 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef double2 
#line 408
double2; 
#endif
#line 409 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef double3 
#line 409
double3; 
#endif
#line 410 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef double4 
#line 410
double4; 
#endif
#line 418 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
#line 418
struct dim3 { 
#line 420
unsigned x, y, z; 
#line 432 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
}; 
#endif
#line 434 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_types.h"
#if 0
typedef dim3 
#line 434
dim3; 
#endif
#line 13 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\limits.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 16
__pragma( pack ( push, 8 )) extern "C" {
#line 76 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\limits.h"
}__pragma( pack ( pop )) 
#line 78
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stddef.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
namespace std { 
#line 25
typedef decltype(nullptr) nullptr_t; 
#line 26
}
#line 28
using std::nullptr_t;
#line 35 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stddef.h"
int *__cdecl _errno(); 
#line 38
errno_t __cdecl _set_errno(int _Value); 
#line 39
errno_t __cdecl _get_errno(int * _Value); 
#line 55 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stddef.h"
extern unsigned long __cdecl __threadid(); 
#line 57
extern uintptr_t __cdecl __threadhandle(); 
#line 61
}__pragma( pack ( pop )) 
#line 63
#pragma warning(pop)
#line 202 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 202
enum cudaError { 
#line 209
cudaSuccess, 
#line 215
cudaErrorInvalidValue, 
#line 221
cudaErrorMemoryAllocation, 
#line 227
cudaErrorInitializationError, 
#line 234
cudaErrorCudartUnloading, 
#line 241
cudaErrorProfilerDisabled, 
#line 249
cudaErrorProfilerNotInitialized, 
#line 256
cudaErrorProfilerAlreadyStarted, 
#line 263
cudaErrorProfilerAlreadyStopped, 
#line 272
cudaErrorInvalidConfiguration, 
#line 278
cudaErrorInvalidPitchValue = 12, 
#line 284
cudaErrorInvalidSymbol, 
#line 292
cudaErrorInvalidHostPointer = 16, 
#line 300
cudaErrorInvalidDevicePointer, 
#line 306
cudaErrorInvalidTexture, 
#line 312
cudaErrorInvalidTextureBinding, 
#line 319
cudaErrorInvalidChannelDescriptor, 
#line 325
cudaErrorInvalidMemcpyDirection, 
#line 335
cudaErrorAddressOfConstant, 
#line 344
cudaErrorTextureFetchFailed, 
#line 353
cudaErrorTextureNotBound, 
#line 362
cudaErrorSynchronizationError, 
#line 368
cudaErrorInvalidFilterSetting, 
#line 374
cudaErrorInvalidNormSetting, 
#line 382
cudaErrorMixedDeviceExecution, 
#line 390
cudaErrorNotYetImplemented = 31, 
#line 399
cudaErrorMemoryValueTooLarge, 
#line 406
cudaErrorStubLibrary = 34, 
#line 413
cudaErrorInsufficientDriver, 
#line 420
cudaErrorCallRequiresNewerDriver, 
#line 426
cudaErrorInvalidSurface, 
#line 432
cudaErrorDuplicateVariableName = 43, 
#line 438
cudaErrorDuplicateTextureName, 
#line 444
cudaErrorDuplicateSurfaceName, 
#line 454
cudaErrorDevicesUnavailable, 
#line 467
cudaErrorIncompatibleDriverContext = 49, 
#line 473
cudaErrorMissingConfiguration = 52, 
#line 482
cudaErrorPriorLaunchFailure, 
#line 489
cudaErrorLaunchMaxDepthExceeded = 65, 
#line 497
cudaErrorLaunchFileScopedTex, 
#line 505
cudaErrorLaunchFileScopedSurf, 
#line 521
cudaErrorSyncDepthExceeded, 
#line 533
cudaErrorLaunchPendingCountExceeded, 
#line 539
cudaErrorInvalidDeviceFunction = 98, 
#line 545
cudaErrorNoDevice = 100, 
#line 552
cudaErrorInvalidDevice, 
#line 557
cudaErrorDeviceNotLicensed, 
#line 566
cudaErrorSoftwareValidityNotEstablished, 
#line 571
cudaErrorStartupFailure = 127, 
#line 576
cudaErrorInvalidKernelImage = 200, 
#line 586
cudaErrorDeviceUninitialized, 
#line 591
cudaErrorMapBufferObjectFailed = 205, 
#line 596
cudaErrorUnmapBufferObjectFailed, 
#line 602
cudaErrorArrayIsMapped, 
#line 607
cudaErrorAlreadyMapped, 
#line 615
cudaErrorNoKernelImageForDevice, 
#line 620
cudaErrorAlreadyAcquired, 
#line 625
cudaErrorNotMapped, 
#line 631
cudaErrorNotMappedAsArray, 
#line 637
cudaErrorNotMappedAsPointer, 
#line 643
cudaErrorECCUncorrectable, 
#line 649
cudaErrorUnsupportedLimit, 
#line 655
cudaErrorDeviceAlreadyInUse, 
#line 661
cudaErrorPeerAccessUnsupported, 
#line 667
cudaErrorInvalidPtx, 
#line 672
cudaErrorInvalidGraphicsContext, 
#line 678
cudaErrorNvlinkUncorrectable, 
#line 685
cudaErrorJitCompilerNotFound, 
#line 692
cudaErrorUnsupportedPtxVersion, 
#line 699
cudaErrorJitCompilationDisabled, 
#line 704
cudaErrorUnsupportedExecAffinity, 
#line 709
cudaErrorInvalidSource = 300, 
#line 714
cudaErrorFileNotFound, 
#line 719
cudaErrorSharedObjectSymbolNotFound, 
#line 724
cudaErrorSharedObjectInitFailed, 
#line 729
cudaErrorOperatingSystem, 
#line 736
cudaErrorInvalidResourceHandle = 400, 
#line 742
cudaErrorIllegalState, 
#line 749
cudaErrorSymbolNotFound = 500, 
#line 757
cudaErrorNotReady = 600, 
#line 765
cudaErrorIllegalAddress = 700, 
#line 774
cudaErrorLaunchOutOfResources, 
#line 785
cudaErrorLaunchTimeout, 
#line 791
cudaErrorLaunchIncompatibleTexturing, 
#line 798
cudaErrorPeerAccessAlreadyEnabled, 
#line 805
cudaErrorPeerAccessNotEnabled, 
#line 818
cudaErrorSetOnActiveProcess = 708, 
#line 825
cudaErrorContextIsDestroyed, 
#line 832
cudaErrorAssert, 
#line 839
cudaErrorTooManyPeers, 
#line 845
cudaErrorHostMemoryAlreadyRegistered, 
#line 851
cudaErrorHostMemoryNotRegistered, 
#line 860
cudaErrorHardwareStackError, 
#line 868
cudaErrorIllegalInstruction, 
#line 877
cudaErrorMisalignedAddress, 
#line 888
cudaErrorInvalidAddressSpace, 
#line 896
cudaErrorInvalidPc, 
#line 907
cudaErrorLaunchFailure, 
#line 916
cudaErrorCooperativeLaunchTooLarge, 
#line 921
cudaErrorNotPermitted = 800, 
#line 927
cudaErrorNotSupported, 
#line 936
cudaErrorSystemNotReady, 
#line 943
cudaErrorSystemDriverMismatch, 
#line 952
cudaErrorCompatNotSupportedOnDevice, 
#line 957
cudaErrorMpsConnectionFailed, 
#line 962
cudaErrorMpsRpcFailure, 
#line 968
cudaErrorMpsServerNotReady, 
#line 973
cudaErrorMpsMaxClientsReached, 
#line 978
cudaErrorMpsMaxConnectionsReached, 
#line 983
cudaErrorMpsClientTerminated, 
#line 988
cudaErrorCdpNotSupported, 
#line 993
cudaErrorCdpVersionMismatch, 
#line 998
cudaErrorStreamCaptureUnsupported = 900, 
#line 1004
cudaErrorStreamCaptureInvalidated, 
#line 1010
cudaErrorStreamCaptureMerge, 
#line 1015
cudaErrorStreamCaptureUnmatched, 
#line 1021
cudaErrorStreamCaptureUnjoined, 
#line 1028
cudaErrorStreamCaptureIsolation, 
#line 1034
cudaErrorStreamCaptureImplicit, 
#line 1040
cudaErrorCapturedEvent, 
#line 1047
cudaErrorStreamCaptureWrongThread, 
#line 1052
cudaErrorTimeout, 
#line 1058
cudaErrorGraphExecUpdateFailure, 
#line 1068
cudaErrorExternalDevice, 
#line 1074
cudaErrorInvalidClusterSize, 
#line 1079
cudaErrorUnknown = 999, 
#line 1087
cudaErrorApiFailureBase = 10000
#line 1088
}; 
#endif
#line 1093 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1093
enum cudaChannelFormatKind { 
#line 1095
cudaChannelFormatKindSigned, 
#line 1096
cudaChannelFormatKindUnsigned, 
#line 1097
cudaChannelFormatKindFloat, 
#line 1098
cudaChannelFormatKindNone, 
#line 1099
cudaChannelFormatKindNV12, 
#line 1100
cudaChannelFormatKindUnsignedNormalized8X1, 
#line 1101
cudaChannelFormatKindUnsignedNormalized8X2, 
#line 1102
cudaChannelFormatKindUnsignedNormalized8X4, 
#line 1103
cudaChannelFormatKindUnsignedNormalized16X1, 
#line 1104
cudaChannelFormatKindUnsignedNormalized16X2, 
#line 1105
cudaChannelFormatKindUnsignedNormalized16X4, 
#line 1106
cudaChannelFormatKindSignedNormalized8X1, 
#line 1107
cudaChannelFormatKindSignedNormalized8X2, 
#line 1108
cudaChannelFormatKindSignedNormalized8X4, 
#line 1109
cudaChannelFormatKindSignedNormalized16X1, 
#line 1110
cudaChannelFormatKindSignedNormalized16X2, 
#line 1111
cudaChannelFormatKindSignedNormalized16X4, 
#line 1112
cudaChannelFormatKindUnsignedBlockCompressed1, 
#line 1113
cudaChannelFormatKindUnsignedBlockCompressed1SRGB, 
#line 1114
cudaChannelFormatKindUnsignedBlockCompressed2, 
#line 1115
cudaChannelFormatKindUnsignedBlockCompressed2SRGB, 
#line 1116
cudaChannelFormatKindUnsignedBlockCompressed3, 
#line 1117
cudaChannelFormatKindUnsignedBlockCompressed3SRGB, 
#line 1118
cudaChannelFormatKindUnsignedBlockCompressed4, 
#line 1119
cudaChannelFormatKindSignedBlockCompressed4, 
#line 1120
cudaChannelFormatKindUnsignedBlockCompressed5, 
#line 1121
cudaChannelFormatKindSignedBlockCompressed5, 
#line 1122
cudaChannelFormatKindUnsignedBlockCompressed6H, 
#line 1123
cudaChannelFormatKindSignedBlockCompressed6H, 
#line 1124
cudaChannelFormatKindUnsignedBlockCompressed7, 
#line 1125
cudaChannelFormatKindUnsignedBlockCompressed7SRGB
#line 1126
}; 
#endif
#line 1131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1131
struct cudaChannelFormatDesc { 
#line 1133
int x; 
#line 1134
int y; 
#line 1135
int z; 
#line 1136
int w; 
#line 1137
cudaChannelFormatKind f; 
#line 1138
}; 
#endif
#line 1143 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
typedef struct cudaArray *cudaArray_t; 
#line 1148
typedef const cudaArray *cudaArray_const_t; 
#line 1150
struct cudaArray; 
#line 1155
typedef struct cudaMipmappedArray *cudaMipmappedArray_t; 
#line 1160
typedef const cudaMipmappedArray *cudaMipmappedArray_const_t; 
#line 1162
struct cudaMipmappedArray; 
#line 1172
#if 0
#line 1172
struct cudaArraySparseProperties { 
#line 1173
struct { 
#line 1174
unsigned width; 
#line 1175
unsigned height; 
#line 1176
unsigned depth; 
#line 1177
} tileExtent; 
#line 1178
unsigned miptailFirstLevel; 
#line 1179
unsigned __int64 miptailSize; 
#line 1180
unsigned flags; 
#line 1181
unsigned reserved[4]; 
#line 1182
}; 
#endif
#line 1187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1187
struct cudaArrayMemoryRequirements { 
#line 1188
size_t size; 
#line 1189
size_t alignment; 
#line 1190
unsigned reserved[4]; 
#line 1191
}; 
#endif
#line 1196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1196
enum cudaMemoryType { 
#line 1198
cudaMemoryTypeUnregistered, 
#line 1199
cudaMemoryTypeHost, 
#line 1200
cudaMemoryTypeDevice, 
#line 1201
cudaMemoryTypeManaged
#line 1202
}; 
#endif
#line 1207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1207
enum cudaMemcpyKind { 
#line 1209
cudaMemcpyHostToHost, 
#line 1210
cudaMemcpyHostToDevice, 
#line 1211
cudaMemcpyDeviceToHost, 
#line 1212
cudaMemcpyDeviceToDevice, 
#line 1213
cudaMemcpyDefault
#line 1214
}; 
#endif
#line 1221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1221
struct cudaPitchedPtr { 
#line 1223
void *ptr; 
#line 1224
size_t pitch; 
#line 1225
size_t xsize; 
#line 1226
size_t ysize; 
#line 1227
}; 
#endif
#line 1234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1234
struct cudaExtent { 
#line 1236
size_t width; 
#line 1237
size_t height; 
#line 1238
size_t depth; 
#line 1239
}; 
#endif
#line 1246 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1246
struct cudaPos { 
#line 1248
size_t x; 
#line 1249
size_t y; 
#line 1250
size_t z; 
#line 1251
}; 
#endif
#line 1256 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1256
struct cudaMemcpy3DParms { 
#line 1258
cudaArray_t srcArray; 
#line 1259
cudaPos srcPos; 
#line 1260
cudaPitchedPtr srcPtr; 
#line 1262
cudaArray_t dstArray; 
#line 1263
cudaPos dstPos; 
#line 1264
cudaPitchedPtr dstPtr; 
#line 1266
cudaExtent extent; 
#line 1267
cudaMemcpyKind kind; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 1268
}; 
#endif
#line 1273 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1273
struct cudaMemcpy3DPeerParms { 
#line 1275
cudaArray_t srcArray; 
#line 1276
cudaPos srcPos; 
#line 1277
cudaPitchedPtr srcPtr; 
#line 1278
int srcDevice; 
#line 1280
cudaArray_t dstArray; 
#line 1281
cudaPos dstPos; 
#line 1282
cudaPitchedPtr dstPtr; 
#line 1283
int dstDevice; 
#line 1285
cudaExtent extent; 
#line 1286
}; 
#endif
#line 1291 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1291
struct cudaMemsetParams { 
#line 1292
void *dst; 
#line 1293
size_t pitch; 
#line 1294
unsigned value; 
#line 1295
unsigned elementSize; 
#line 1296
size_t width; 
#line 1297
size_t height; 
#line 1298
}; 
#endif
#line 1303 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1303
enum cudaAccessProperty { 
#line 1304
cudaAccessPropertyNormal, 
#line 1305
cudaAccessPropertyStreaming, 
#line 1306
cudaAccessPropertyPersisting
#line 1307
}; 
#endif
#line 1320 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1320
struct cudaAccessPolicyWindow { 
#line 1321
void *base_ptr; 
#line 1322
size_t num_bytes; 
#line 1323
float hitRatio; 
#line 1324
cudaAccessProperty hitProp; 
#line 1325
cudaAccessProperty missProp; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 1326
}; 
#endif
#line 1338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
typedef void (__stdcall *cudaHostFn_t)(void * userData); 
#line 1343
#if 0
#line 1343
struct cudaHostNodeParams { 
#line 1344
cudaHostFn_t fn; 
#line 1345
void *userData; 
#line 1346
}; 
#endif
#line 1351 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1351
enum cudaStreamCaptureStatus { 
#line 1352
cudaStreamCaptureStatusNone, 
#line 1353
cudaStreamCaptureStatusActive, 
#line 1354
cudaStreamCaptureStatusInvalidated
#line 1356
}; 
#endif
#line 1362 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1362
enum cudaStreamCaptureMode { 
#line 1363
cudaStreamCaptureModeGlobal, 
#line 1364
cudaStreamCaptureModeThreadLocal, 
#line 1365
cudaStreamCaptureModeRelaxed
#line 1366
}; 
#endif
#line 1368 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1368
enum cudaSynchronizationPolicy { 
#line 1369
cudaSyncPolicyAuto = 1, 
#line 1370
cudaSyncPolicySpin, 
#line 1371
cudaSyncPolicyYield, 
#line 1372
cudaSyncPolicyBlockingSync
#line 1373
}; 
#endif
#line 1378 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1378
enum cudaClusterSchedulingPolicy { 
#line 1379
cudaClusterSchedulingPolicyDefault, 
#line 1380
cudaClusterSchedulingPolicySpread, 
#line 1381
cudaClusterSchedulingPolicyLoadBalancing
#line 1382
}; 
#endif
#line 1387 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1387
enum cudaStreamUpdateCaptureDependenciesFlags { 
#line 1388
cudaStreamAddCaptureDependencies, 
#line 1389
cudaStreamSetCaptureDependencies
#line 1390
}; 
#endif
#line 1395 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1395
enum cudaUserObjectFlags { 
#line 1396
cudaUserObjectNoDestructorSync = 1
#line 1397
}; 
#endif
#line 1402 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1402
enum cudaUserObjectRetainFlags { 
#line 1403
cudaGraphUserObjectMove = 1
#line 1404
}; 
#endif
#line 1409 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
struct cudaGraphicsResource; 
#line 1414
#if 0
#line 1414
enum cudaGraphicsRegisterFlags { 
#line 1416
cudaGraphicsRegisterFlagsNone, 
#line 1417
cudaGraphicsRegisterFlagsReadOnly, 
#line 1418
cudaGraphicsRegisterFlagsWriteDiscard, 
#line 1419
cudaGraphicsRegisterFlagsSurfaceLoadStore = 4, 
#line 1420
cudaGraphicsRegisterFlagsTextureGather = 8
#line 1421
}; 
#endif
#line 1426 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1426
enum cudaGraphicsMapFlags { 
#line 1428
cudaGraphicsMapFlagsNone, 
#line 1429
cudaGraphicsMapFlagsReadOnly, 
#line 1430
cudaGraphicsMapFlagsWriteDiscard
#line 1431
}; 
#endif
#line 1436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1436
enum cudaGraphicsCubeFace { 
#line 1438
cudaGraphicsCubeFacePositiveX, 
#line 1439
cudaGraphicsCubeFaceNegativeX, 
#line 1440
cudaGraphicsCubeFacePositiveY, 
#line 1441
cudaGraphicsCubeFaceNegativeY, 
#line 1442
cudaGraphicsCubeFacePositiveZ, 
#line 1443
cudaGraphicsCubeFaceNegativeZ
#line 1444
}; 
#endif
#line 1449 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1449
enum cudaResourceType { 
#line 1451
cudaResourceTypeArray, 
#line 1452
cudaResourceTypeMipmappedArray, 
#line 1453
cudaResourceTypeLinear, 
#line 1454
cudaResourceTypePitch2D
#line 1455
}; 
#endif
#line 1460 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1460
enum cudaResourceViewFormat { 
#line 1462
cudaResViewFormatNone, 
#line 1463
cudaResViewFormatUnsignedChar1, 
#line 1464
cudaResViewFormatUnsignedChar2, 
#line 1465
cudaResViewFormatUnsignedChar4, 
#line 1466
cudaResViewFormatSignedChar1, 
#line 1467
cudaResViewFormatSignedChar2, 
#line 1468
cudaResViewFormatSignedChar4, 
#line 1469
cudaResViewFormatUnsignedShort1, 
#line 1470
cudaResViewFormatUnsignedShort2, 
#line 1471
cudaResViewFormatUnsignedShort4, 
#line 1472
cudaResViewFormatSignedShort1, 
#line 1473
cudaResViewFormatSignedShort2, 
#line 1474
cudaResViewFormatSignedShort4, 
#line 1475
cudaResViewFormatUnsignedInt1, 
#line 1476
cudaResViewFormatUnsignedInt2, 
#line 1477
cudaResViewFormatUnsignedInt4, 
#line 1478
cudaResViewFormatSignedInt1, 
#line 1479
cudaResViewFormatSignedInt2, 
#line 1480
cudaResViewFormatSignedInt4, 
#line 1481
cudaResViewFormatHalf1, 
#line 1482
cudaResViewFormatHalf2, 
#line 1483
cudaResViewFormatHalf4, 
#line 1484
cudaResViewFormatFloat1, 
#line 1485
cudaResViewFormatFloat2, 
#line 1486
cudaResViewFormatFloat4, 
#line 1487
cudaResViewFormatUnsignedBlockCompressed1, 
#line 1488
cudaResViewFormatUnsignedBlockCompressed2, 
#line 1489
cudaResViewFormatUnsignedBlockCompressed3, 
#line 1490
cudaResViewFormatUnsignedBlockCompressed4, 
#line 1491
cudaResViewFormatSignedBlockCompressed4, 
#line 1492
cudaResViewFormatUnsignedBlockCompressed5, 
#line 1493
cudaResViewFormatSignedBlockCompressed5, 
#line 1494
cudaResViewFormatUnsignedBlockCompressed6H, 
#line 1495
cudaResViewFormatSignedBlockCompressed6H, 
#line 1496
cudaResViewFormatUnsignedBlockCompressed7
#line 1497
}; 
#endif
#line 1502 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1502
struct cudaResourceDesc { 
#line 1503
cudaResourceType resType; 
#line 1505
union { 
#line 1506
struct { 
#line 1507
cudaArray_t array; 
#line 1508
} array; 
#line 1509
struct { 
#line 1510
cudaMipmappedArray_t mipmap; 
#line 1511
} mipmap; 
#line 1512
struct { 
#line 1513
void *devPtr; 
#line 1514
cudaChannelFormatDesc desc; 
#line 1515
size_t sizeInBytes; 
#line 1516
} linear; 
#line 1517
struct { 
#line 1518
void *devPtr; 
#line 1519
cudaChannelFormatDesc desc; 
#line 1520
size_t width; 
#line 1521
size_t height; 
#line 1522
size_t pitchInBytes; 
#line 1523
} pitch2D; 
#line 1524
} res; 
#line 1525
}; 
#endif
#line 1530 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1530
struct cudaResourceViewDesc { 
#line 1532
cudaResourceViewFormat format; 
#line 1533
size_t width; 
#line 1534
size_t height; 
#line 1535
size_t depth; 
#line 1536
unsigned firstMipmapLevel; 
#line 1537
unsigned lastMipmapLevel; 
#line 1538
unsigned firstLayer; 
#line 1539
unsigned lastLayer; 
#line 1540
}; 
#endif
#line 1545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1545
struct cudaPointerAttributes { 
#line 1551
cudaMemoryType type; 
#line 1562
int device; 
#line 1568
void *devicePointer; 
#line 1577
void *hostPointer; 
#line 1578
}; 
#endif
#line 1583 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1583
struct cudaFuncAttributes { 
#line 1590
size_t sharedSizeBytes; 
#line 1596
size_t constSizeBytes; 
#line 1601
size_t localSizeBytes; 
#line 1608
int maxThreadsPerBlock; 
#line 1613
int numRegs; 
#line 1620
int ptxVersion; 
#line 1627
int binaryVersion; 
#line 1633
int cacheModeCA; 
#line 1640
int maxDynamicSharedSizeBytes; 
#line 1649
int preferredShmemCarveout; 
#line 1655
int clusterDimMustBeSet; 
#line 1666
int requiredClusterWidth; 
#line 1667
int requiredClusterHeight; 
#line 1668
int requiredClusterDepth; 
#line 1674
int clusterSchedulingPolicyPreference; 
#line 1696
int nonPortableClusterSizeAllowed; 
#line 1701
int reserved[16]; 
#line 1702
}; 
#endif
#line 1707 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1707
enum cudaFuncAttribute { 
#line 1709
cudaFuncAttributeMaxDynamicSharedMemorySize = 8, 
#line 1710
cudaFuncAttributePreferredSharedMemoryCarveout, 
#line 1711
cudaFuncAttributeClusterDimMustBeSet, 
#line 1712
cudaFuncAttributeRequiredClusterWidth, 
#line 1713
cudaFuncAttributeRequiredClusterHeight, 
#line 1714
cudaFuncAttributeRequiredClusterDepth, 
#line 1715
cudaFuncAttributeNonPortableClusterSizeAllowed, 
#line 1716
cudaFuncAttributeClusterSchedulingPolicyPreference, 
#line 1717
cudaFuncAttributeMax
#line 1718
}; 
#endif
#line 1723 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1723
enum cudaFuncCache { 
#line 1725
cudaFuncCachePreferNone, 
#line 1726
cudaFuncCachePreferShared, 
#line 1727
cudaFuncCachePreferL1, 
#line 1728
cudaFuncCachePreferEqual
#line 1729
}; 
#endif
#line 1735 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1735
enum cudaSharedMemConfig { 
#line 1737
cudaSharedMemBankSizeDefault, 
#line 1738
cudaSharedMemBankSizeFourByte, 
#line 1739
cudaSharedMemBankSizeEightByte
#line 1740
}; 
#endif
#line 1745 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1745
enum cudaSharedCarveout { 
#line 1746
cudaSharedmemCarveoutDefault = (-1), 
#line 1747
cudaSharedmemCarveoutMaxShared = 100, 
#line 1748
cudaSharedmemCarveoutMaxL1 = 0
#line 1749
}; 
#endif
#line 1754 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1754
enum cudaComputeMode { 
#line 1756
cudaComputeModeDefault, 
#line 1757
cudaComputeModeExclusive, 
#line 1758
cudaComputeModeProhibited, 
#line 1759
cudaComputeModeExclusiveProcess
#line 1760
}; 
#endif
#line 1765 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1765
enum cudaLimit { 
#line 1767
cudaLimitStackSize, 
#line 1768
cudaLimitPrintfFifoSize, 
#line 1769
cudaLimitMallocHeapSize, 
#line 1770
cudaLimitDevRuntimeSyncDepth, 
#line 1771
cudaLimitDevRuntimePendingLaunchCount, 
#line 1772
cudaLimitMaxL2FetchGranularity, 
#line 1773
cudaLimitPersistingL2CacheSize
#line 1774
}; 
#endif
#line 1779 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1779
enum cudaMemoryAdvise { 
#line 1781
cudaMemAdviseSetReadMostly = 1, 
#line 1782
cudaMemAdviseUnsetReadMostly, 
#line 1783
cudaMemAdviseSetPreferredLocation, 
#line 1784
cudaMemAdviseUnsetPreferredLocation, 
#line 1785
cudaMemAdviseSetAccessedBy, 
#line 1786
cudaMemAdviseUnsetAccessedBy
#line 1787
}; 
#endif
#line 1792 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1792
enum cudaMemRangeAttribute { 
#line 1794
cudaMemRangeAttributeReadMostly = 1, 
#line 1795
cudaMemRangeAttributePreferredLocation, 
#line 1796
cudaMemRangeAttributeAccessedBy, 
#line 1797
cudaMemRangeAttributeLastPrefetchLocation
#line 1798
}; 
#endif
#line 1803 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1803
enum cudaFlushGPUDirectRDMAWritesOptions { 
#line 1804
cudaFlushGPUDirectRDMAWritesOptionHost = (1 << 0), 
#line 1805
cudaFlushGPUDirectRDMAWritesOptionMemOps
#line 1806
}; 
#endif
#line 1811 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1811
enum cudaGPUDirectRDMAWritesOrdering { 
#line 1812
cudaGPUDirectRDMAWritesOrderingNone, 
#line 1813
cudaGPUDirectRDMAWritesOrderingOwner = 100, 
#line 1814
cudaGPUDirectRDMAWritesOrderingAllDevices = 200
#line 1815
}; 
#endif
#line 1820 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1820
enum cudaFlushGPUDirectRDMAWritesScope { 
#line 1821
cudaFlushGPUDirectRDMAWritesToOwner = 100, 
#line 1822
cudaFlushGPUDirectRDMAWritesToAllDevices = 200
#line 1823
}; 
#endif
#line 1828 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1828
enum cudaFlushGPUDirectRDMAWritesTarget { 
#line 1829
cudaFlushGPUDirectRDMAWritesTargetCurrentDevice
#line 1830
}; 
#endif
#line 1836 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1836
enum cudaDeviceAttr { 
#line 1838
cudaDevAttrMaxThreadsPerBlock = 1, 
#line 1839
cudaDevAttrMaxBlockDimX, 
#line 1840
cudaDevAttrMaxBlockDimY, 
#line 1841
cudaDevAttrMaxBlockDimZ, 
#line 1842
cudaDevAttrMaxGridDimX, 
#line 1843
cudaDevAttrMaxGridDimY, 
#line 1844
cudaDevAttrMaxGridDimZ, 
#line 1845
cudaDevAttrMaxSharedMemoryPerBlock, 
#line 1846
cudaDevAttrTotalConstantMemory, 
#line 1847
cudaDevAttrWarpSize, 
#line 1848
cudaDevAttrMaxPitch, 
#line 1849
cudaDevAttrMaxRegistersPerBlock, 
#line 1850
cudaDevAttrClockRate, 
#line 1851
cudaDevAttrTextureAlignment, 
#line 1852
cudaDevAttrGpuOverlap, 
#line 1853
cudaDevAttrMultiProcessorCount, 
#line 1854
cudaDevAttrKernelExecTimeout, 
#line 1855
cudaDevAttrIntegrated, 
#line 1856
cudaDevAttrCanMapHostMemory, 
#line 1857
cudaDevAttrComputeMode, 
#line 1858
cudaDevAttrMaxTexture1DWidth, 
#line 1859
cudaDevAttrMaxTexture2DWidth, 
#line 1860
cudaDevAttrMaxTexture2DHeight, 
#line 1861
cudaDevAttrMaxTexture3DWidth, 
#line 1862
cudaDevAttrMaxTexture3DHeight, 
#line 1863
cudaDevAttrMaxTexture3DDepth, 
#line 1864
cudaDevAttrMaxTexture2DLayeredWidth, 
#line 1865
cudaDevAttrMaxTexture2DLayeredHeight, 
#line 1866
cudaDevAttrMaxTexture2DLayeredLayers, 
#line 1867
cudaDevAttrSurfaceAlignment, 
#line 1868
cudaDevAttrConcurrentKernels, 
#line 1869
cudaDevAttrEccEnabled, 
#line 1870
cudaDevAttrPciBusId, 
#line 1871
cudaDevAttrPciDeviceId, 
#line 1872
cudaDevAttrTccDriver, 
#line 1873
cudaDevAttrMemoryClockRate, 
#line 1874
cudaDevAttrGlobalMemoryBusWidth, 
#line 1875
cudaDevAttrL2CacheSize, 
#line 1876
cudaDevAttrMaxThreadsPerMultiProcessor, 
#line 1877
cudaDevAttrAsyncEngineCount, 
#line 1878
cudaDevAttrUnifiedAddressing, 
#line 1879
cudaDevAttrMaxTexture1DLayeredWidth, 
#line 1880
cudaDevAttrMaxTexture1DLayeredLayers, 
#line 1881
cudaDevAttrMaxTexture2DGatherWidth = 45, 
#line 1882
cudaDevAttrMaxTexture2DGatherHeight, 
#line 1883
cudaDevAttrMaxTexture3DWidthAlt, 
#line 1884
cudaDevAttrMaxTexture3DHeightAlt, 
#line 1885
cudaDevAttrMaxTexture3DDepthAlt, 
#line 1886
cudaDevAttrPciDomainId, 
#line 1887
cudaDevAttrTexturePitchAlignment, 
#line 1888
cudaDevAttrMaxTextureCubemapWidth, 
#line 1889
cudaDevAttrMaxTextureCubemapLayeredWidth, 
#line 1890
cudaDevAttrMaxTextureCubemapLayeredLayers, 
#line 1891
cudaDevAttrMaxSurface1DWidth, 
#line 1892
cudaDevAttrMaxSurface2DWidth, 
#line 1893
cudaDevAttrMaxSurface2DHeight, 
#line 1894
cudaDevAttrMaxSurface3DWidth, 
#line 1895
cudaDevAttrMaxSurface3DHeight, 
#line 1896
cudaDevAttrMaxSurface3DDepth, 
#line 1897
cudaDevAttrMaxSurface1DLayeredWidth, 
#line 1898
cudaDevAttrMaxSurface1DLayeredLayers, 
#line 1899
cudaDevAttrMaxSurface2DLayeredWidth, 
#line 1900
cudaDevAttrMaxSurface2DLayeredHeight, 
#line 1901
cudaDevAttrMaxSurface2DLayeredLayers, 
#line 1902
cudaDevAttrMaxSurfaceCubemapWidth, 
#line 1903
cudaDevAttrMaxSurfaceCubemapLayeredWidth, 
#line 1904
cudaDevAttrMaxSurfaceCubemapLayeredLayers, 
#line 1905
cudaDevAttrMaxTexture1DLinearWidth, 
#line 1906
cudaDevAttrMaxTexture2DLinearWidth, 
#line 1907
cudaDevAttrMaxTexture2DLinearHeight, 
#line 1908
cudaDevAttrMaxTexture2DLinearPitch, 
#line 1909
cudaDevAttrMaxTexture2DMipmappedWidth, 
#line 1910
cudaDevAttrMaxTexture2DMipmappedHeight, 
#line 1911
cudaDevAttrComputeCapabilityMajor, 
#line 1912
cudaDevAttrComputeCapabilityMinor, 
#line 1913
cudaDevAttrMaxTexture1DMipmappedWidth, 
#line 1914
cudaDevAttrStreamPrioritiesSupported, 
#line 1915
cudaDevAttrGlobalL1CacheSupported, 
#line 1916
cudaDevAttrLocalL1CacheSupported, 
#line 1917
cudaDevAttrMaxSharedMemoryPerMultiprocessor, 
#line 1918
cudaDevAttrMaxRegistersPerMultiprocessor, 
#line 1919
cudaDevAttrManagedMemory, 
#line 1920
cudaDevAttrIsMultiGpuBoard, 
#line 1921
cudaDevAttrMultiGpuBoardGroupID, 
#line 1922
cudaDevAttrHostNativeAtomicSupported, 
#line 1923
cudaDevAttrSingleToDoublePrecisionPerfRatio, 
#line 1924
cudaDevAttrPageableMemoryAccess, 
#line 1925
cudaDevAttrConcurrentManagedAccess, 
#line 1926
cudaDevAttrComputePreemptionSupported, 
#line 1927
cudaDevAttrCanUseHostPointerForRegisteredMem, 
#line 1928
cudaDevAttrReserved92, 
#line 1929
cudaDevAttrReserved93, 
#line 1930
cudaDevAttrReserved94, 
#line 1931
cudaDevAttrCooperativeLaunch, 
#line 1932
cudaDevAttrCooperativeMultiDeviceLaunch, 
#line 1933
cudaDevAttrMaxSharedMemoryPerBlockOptin, 
#line 1934
cudaDevAttrCanFlushRemoteWrites, 
#line 1935
cudaDevAttrHostRegisterSupported, 
#line 1936
cudaDevAttrPageableMemoryAccessUsesHostPageTables, 
#line 1937
cudaDevAttrDirectManagedMemAccessFromHost, 
#line 1938
cudaDevAttrMaxBlocksPerMultiprocessor = 106, 
#line 1939
cudaDevAttrMaxPersistingL2CacheSize = 108, 
#line 1940
cudaDevAttrMaxAccessPolicyWindowSize, 
#line 1941
cudaDevAttrReservedSharedMemoryPerBlock = 111, 
#line 1942
cudaDevAttrSparseCudaArraySupported, 
#line 1943
cudaDevAttrHostRegisterReadOnlySupported, 
#line 1944
cudaDevAttrTimelineSemaphoreInteropSupported, 
#line 1945
cudaDevAttrMaxTimelineSemaphoreInteropSupported = 114, 
#line 1946
cudaDevAttrMemoryPoolsSupported, 
#line 1947
cudaDevAttrGPUDirectRDMASupported, 
#line 1948
cudaDevAttrGPUDirectRDMAFlushWritesOptions, 
#line 1949
cudaDevAttrGPUDirectRDMAWritesOrdering, 
#line 1950
cudaDevAttrMemoryPoolSupportedHandleTypes, 
#line 1951
cudaDevAttrClusterLaunch, 
#line 1952
cudaDevAttrDeferredMappingCudaArraySupported, 
#line 1953
cudaDevAttrReserved122, 
#line 1954
cudaDevAttrReserved123, 
#line 1955
cudaDevAttrReserved124, 
#line 1956
cudaDevAttrIpcEventSupport, 
#line 1957
cudaDevAttrMemSyncDomainCount, 
#line 1958
cudaDevAttrMax
#line 1959
}; 
#endif
#line 1964 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 1964
enum cudaMemPoolAttr { 
#line 1974
cudaMemPoolReuseFollowEventDependencies = 1, 
#line 1981
cudaMemPoolReuseAllowOpportunistic, 
#line 1989
cudaMemPoolReuseAllowInternalDependencies, 
#line 2000
cudaMemPoolAttrReleaseThreshold, 
#line 2006
cudaMemPoolAttrReservedMemCurrent, 
#line 2013
cudaMemPoolAttrReservedMemHigh, 
#line 2019
cudaMemPoolAttrUsedMemCurrent, 
#line 2026
cudaMemPoolAttrUsedMemHigh
#line 2027
}; 
#endif
#line 2032 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2032
enum cudaMemLocationType { 
#line 2033
cudaMemLocationTypeInvalid, 
#line 2034
cudaMemLocationTypeDevice
#line 2035
}; 
#endif
#line 2042 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2042
struct cudaMemLocation { 
#line 2043
cudaMemLocationType type; 
#line 2044
int id; 
#line 2045
}; 
#endif
#line 2050 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2050
enum cudaMemAccessFlags { 
#line 2051
cudaMemAccessFlagsProtNone, 
#line 2052
cudaMemAccessFlagsProtRead, 
#line 2053
cudaMemAccessFlagsProtReadWrite = 3
#line 2054
}; 
#endif
#line 2059 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2059
struct cudaMemAccessDesc { 
#line 2060
cudaMemLocation location; 
#line 2061
cudaMemAccessFlags flags; 
#line 2062
}; 
#endif
#line 2067 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2067
enum cudaMemAllocationType { 
#line 2068
cudaMemAllocationTypeInvalid, 
#line 2072
cudaMemAllocationTypePinned, 
#line 2073
cudaMemAllocationTypeMax = 2147483647
#line 2074
}; 
#endif
#line 2079 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2079
enum cudaMemAllocationHandleType { 
#line 2080
cudaMemHandleTypeNone, 
#line 2081
cudaMemHandleTypePosixFileDescriptor, 
#line 2082
cudaMemHandleTypeWin32, 
#line 2083
cudaMemHandleTypeWin32Kmt = 4
#line 2084
}; 
#endif
#line 2089 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2089
struct cudaMemPoolProps { 
#line 2090
cudaMemAllocationType allocType; 
#line 2091
cudaMemAllocationHandleType handleTypes; 
#line 2092
cudaMemLocation location; 
#line 2099
void *win32SecurityAttributes; 
#line 2100
unsigned char reserved[64]; 
#line 2101
}; 
#endif
#line 2106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2106
struct cudaMemPoolPtrExportData { 
#line 2107
unsigned char reserved[64]; 
#line 2108
}; 
#endif
#line 2113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2113
struct cudaMemAllocNodeParams { 
#line 2118
cudaMemPoolProps poolProps; 
#line 2119
const cudaMemAccessDesc *accessDescs; 
#line 2120
size_t accessDescCount; 
#line 2121
size_t bytesize; 
#line 2122
void *dptr; 
#line 2123
}; 
#endif
#line 2128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2128
enum cudaGraphMemAttributeType { 
#line 2133
cudaGraphMemAttrUsedMemCurrent, 
#line 2140
cudaGraphMemAttrUsedMemHigh, 
#line 2147
cudaGraphMemAttrReservedMemCurrent, 
#line 2154
cudaGraphMemAttrReservedMemHigh
#line 2155
}; 
#endif
#line 2161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2161
enum cudaDeviceP2PAttr { 
#line 2162
cudaDevP2PAttrPerformanceRank = 1, 
#line 2163
cudaDevP2PAttrAccessSupported, 
#line 2164
cudaDevP2PAttrNativeAtomicSupported, 
#line 2165
cudaDevP2PAttrCudaArrayAccessSupported
#line 2166
}; 
#endif
#line 2173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2173
struct CUuuid_st { 
#line 2174
char bytes[16]; 
#line 2175
}; 
#endif
#line 2176 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef CUuuid_st 
#line 2176
CUuuid; 
#endif
#line 2178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef CUuuid_st 
#line 2178
cudaUUID_t; 
#endif
#line 2183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2183
struct cudaDeviceProp { 
#line 2185
char name[256]; 
#line 2186
cudaUUID_t uuid; 
#line 2187
char luid[8]; 
#line 2188
unsigned luidDeviceNodeMask; 
#line 2189
size_t totalGlobalMem; 
#line 2190
size_t sharedMemPerBlock; 
#line 2191
int regsPerBlock; 
#line 2192
int warpSize; 
#line 2193
size_t memPitch; 
#line 2194
int maxThreadsPerBlock; 
#line 2195
int maxThreadsDim[3]; 
#line 2196
int maxGridSize[3]; 
#line 2197
int clockRate; 
#line 2198
size_t totalConstMem; 
#line 2199
int major; 
#line 2200
int minor; 
#line 2201
size_t textureAlignment; 
#line 2202
size_t texturePitchAlignment; 
#line 2203
int deviceOverlap; 
#line 2204
int multiProcessorCount; 
#line 2205
int kernelExecTimeoutEnabled; 
#line 2206
int integrated; 
#line 2207
int canMapHostMemory; 
#line 2208
int computeMode; 
#line 2209
int maxTexture1D; 
#line 2210
int maxTexture1DMipmap; 
#line 2211
int maxTexture1DLinear; 
#line 2212
int maxTexture2D[2]; 
#line 2213
int maxTexture2DMipmap[2]; 
#line 2214
int maxTexture2DLinear[3]; 
#line 2215
int maxTexture2DGather[2]; 
#line 2216
int maxTexture3D[3]; 
#line 2217
int maxTexture3DAlt[3]; 
#line 2218
int maxTextureCubemap; 
#line 2219
int maxTexture1DLayered[2]; 
#line 2220
int maxTexture2DLayered[3]; 
#line 2221
int maxTextureCubemapLayered[2]; 
#line 2222
int maxSurface1D; 
#line 2223
int maxSurface2D[2]; 
#line 2224
int maxSurface3D[3]; 
#line 2225
int maxSurface1DLayered[2]; 
#line 2226
int maxSurface2DLayered[3]; 
#line 2227
int maxSurfaceCubemap; 
#line 2228
int maxSurfaceCubemapLayered[2]; 
#line 2229
size_t surfaceAlignment; 
#line 2230
int concurrentKernels; 
#line 2231
int ECCEnabled; 
#line 2232
int pciBusID; 
#line 2233
int pciDeviceID; 
#line 2234
int pciDomainID; 
#line 2235
int tccDriver; 
#line 2236
int asyncEngineCount; 
#line 2237
int unifiedAddressing; 
#line 2238
int memoryClockRate; 
#line 2239
int memoryBusWidth; 
#line 2240
int l2CacheSize; 
#line 2241
int persistingL2CacheMaxSize; 
#line 2242
int maxThreadsPerMultiProcessor; 
#line 2243
int streamPrioritiesSupported; 
#line 2244
int globalL1CacheSupported; 
#line 2245
int localL1CacheSupported; 
#line 2246
size_t sharedMemPerMultiprocessor; 
#line 2247
int regsPerMultiprocessor; 
#line 2248
int managedMemory; 
#line 2249
int isMultiGpuBoard; 
#line 2250
int multiGpuBoardGroupID; 
#line 2251
int hostNativeAtomicSupported; 
#line 2252
int singleToDoublePrecisionPerfRatio; 
#line 2253
int pageableMemoryAccess; 
#line 2254
int concurrentManagedAccess; 
#line 2255
int computePreemptionSupported; 
#line 2256
int canUseHostPointerForRegisteredMem; 
#line 2257
int cooperativeLaunch; 
#line 2258
int cooperativeMultiDeviceLaunch; 
#line 2259
size_t sharedMemPerBlockOptin; 
#line 2260
int pageableMemoryAccessUsesHostPageTables; 
#line 2261
int directManagedMemAccessFromHost; 
#line 2262
int maxBlocksPerMultiProcessor; 
#line 2263
int accessPolicyMaxWindowSize; 
#line 2264
size_t reservedSharedMemPerBlock; 
#line 2265
int hostRegisterSupported; 
#line 2266
int sparseCudaArraySupported; 
#line 2267
int hostRegisterReadOnlySupported; 
#line 2268
int timelineSemaphoreInteropSupported; 
#line 2269
int memoryPoolsSupported; 
#line 2270
int gpuDirectRDMASupported; 
#line 2271
unsigned gpuDirectRDMAFlushWritesOptions; 
#line 2272
int gpuDirectRDMAWritesOrdering; 
#line 2273
unsigned memoryPoolSupportedHandleTypes; 
#line 2274
int deferredMappingCudaArraySupported; 
#line 2275
int ipcEventSupported; 
#line 2276
int clusterLaunch; 
#line 2277
int unifiedFunctionPointers; 
#line 2278
int reserved[63]; 
#line 2279
}; 
#endif
#line 2292 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 2289
struct cudaIpcEventHandle_st { 
#line 2291
char reserved[64]; 
#line 2292
} cudaIpcEventHandle_t; 
#endif
#line 2300 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 2297
struct cudaIpcMemHandle_st { 
#line 2299
char reserved[64]; 
#line 2300
} cudaIpcMemHandle_t; 
#endif
#line 2305 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2305
enum cudaExternalMemoryHandleType { 
#line 2309
cudaExternalMemoryHandleTypeOpaqueFd = 1, 
#line 2313
cudaExternalMemoryHandleTypeOpaqueWin32, 
#line 2317
cudaExternalMemoryHandleTypeOpaqueWin32Kmt, 
#line 2321
cudaExternalMemoryHandleTypeD3D12Heap, 
#line 2325
cudaExternalMemoryHandleTypeD3D12Resource, 
#line 2329
cudaExternalMemoryHandleTypeD3D11Resource, 
#line 2333
cudaExternalMemoryHandleTypeD3D11ResourceKmt, 
#line 2337
cudaExternalMemoryHandleTypeNvSciBuf
#line 2338
}; 
#endif
#line 2380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2380
struct cudaExternalMemoryHandleDesc { 
#line 2384
cudaExternalMemoryHandleType type; 
#line 2385
union { 
#line 2391
int fd; 
#line 2407
struct { 
#line 2411
void *handle; 
#line 2416
const void *name; 
#line 2417
} win32; 
#line 2422
const void *nvSciBufObject; 
#line 2423
} handle; 
#line 2427
unsigned __int64 size; 
#line 2431
unsigned flags; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 2432
}; 
#endif
#line 2437 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2437
struct cudaExternalMemoryBufferDesc { 
#line 2441
unsigned __int64 offset; 
#line 2445
unsigned __int64 size; 
#line 2449
unsigned flags; 
#line 2450
}; 
#endif
#line 2455 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2455
struct cudaExternalMemoryMipmappedArrayDesc { 
#line 2460
unsigned __int64 offset; 
#line 2464
cudaChannelFormatDesc formatDesc; 
#line 2468
cudaExtent extent; 
#line 2473
unsigned flags; 
#line 2477
unsigned numLevels; 
#line 2478
}; 
#endif
#line 2483 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2483
enum cudaExternalSemaphoreHandleType { 
#line 2487
cudaExternalSemaphoreHandleTypeOpaqueFd = 1, 
#line 2491
cudaExternalSemaphoreHandleTypeOpaqueWin32, 
#line 2495
cudaExternalSemaphoreHandleTypeOpaqueWin32Kmt, 
#line 2499
cudaExternalSemaphoreHandleTypeD3D12Fence, 
#line 2503
cudaExternalSemaphoreHandleTypeD3D11Fence, 
#line 2507
cudaExternalSemaphoreHandleTypeNvSciSync, 
#line 2511
cudaExternalSemaphoreHandleTypeKeyedMutex, 
#line 2515
cudaExternalSemaphoreHandleTypeKeyedMutexKmt, 
#line 2519
cudaExternalSemaphoreHandleTypeTimelineSemaphoreFd, 
#line 2523
cudaExternalSemaphoreHandleTypeTimelineSemaphoreWin32
#line 2524
}; 
#endif
#line 2529 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2529
struct cudaExternalSemaphoreHandleDesc { 
#line 2533
cudaExternalSemaphoreHandleType type; 
#line 2534
union { 
#line 2541
int fd; 
#line 2557
struct { 
#line 2561
void *handle; 
#line 2566
const void *name; 
#line 2567
} win32; 
#line 2571
const void *nvSciSyncObj; 
#line 2572
} handle; 
#line 2576
unsigned flags; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 2577
}; 
#endif
#line 2582 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2582
struct cudaExternalSemaphoreSignalParams_v1 { 
#line 2583
struct { 
#line 2587
struct { 
#line 2591
unsigned __int64 value; 
#line 2592
} fence; 
#line 2593
union { 
#line 2598
void *fence; 
#line 2599
unsigned __int64 reserved; 
#line 2600
} nvSciSync; 
#line 2604
struct { 
#line 2608
unsigned __int64 key; 
#line 2609
} keyedMutex; 
#line 2610
} params; 
#line 2621
unsigned flags; 
#line 2622
}; 
#endif
#line 2627 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2627
struct cudaExternalSemaphoreWaitParams_v1 { 
#line 2628
struct { 
#line 2632
struct { 
#line 2636
unsigned __int64 value; 
#line 2637
} fence; 
#line 2638
union { 
#line 2643
void *fence; 
#line 2644
unsigned __int64 reserved; 
#line 2645
} nvSciSync; 
#line 2649
struct { 
#line 2653
unsigned __int64 key; 
#line 2657
unsigned timeoutMs; 
#line 2658
} keyedMutex; 
#line 2659
} params; 
#line 2670
unsigned flags; 
#line 2671
}; 
#endif
#line 2676 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2676
struct cudaExternalSemaphoreSignalParams { 
#line 2677
struct { 
#line 2681
struct { 
#line 2685
unsigned __int64 value; 
#line 2686
} fence; 
#line 2687
union { 
#line 2692
void *fence; 
#line 2693
unsigned __int64 reserved; 
#line 2694
} nvSciSync; 
#line 2698
struct { 
#line 2702
unsigned __int64 key; 
#line 2703
} keyedMutex; 
#line 2704
unsigned reserved[12]; 
#line 2705
} params; 
#line 2716
unsigned flags; 
#line 2717
unsigned reserved[16]; 
#line 2718
}; 
#endif
#line 2723 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2723
struct cudaExternalSemaphoreWaitParams { 
#line 2724
struct { 
#line 2728
struct { 
#line 2732
unsigned __int64 value; 
#line 2733
} fence; 
#line 2734
union { 
#line 2739
void *fence; 
#line 2740
unsigned __int64 reserved; 
#line 2741
} nvSciSync; 
#line 2745
struct { 
#line 2749
unsigned __int64 key; 
#line 2753
unsigned timeoutMs; 
#line 2754
} keyedMutex; 
#line 2755
unsigned reserved[10]; 
#line 2756
} params; 
#line 2767
unsigned flags; 
#line 2768
unsigned reserved[16]; 
#line 2769
}; 
#endif
#line 2780 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef cudaError 
#line 2780
cudaError_t; 
#endif
#line 2785 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUstream_st *
#line 2785
cudaStream_t; 
#endif
#line 2790 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUevent_st *
#line 2790
cudaEvent_t; 
#endif
#line 2795 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef cudaGraphicsResource *
#line 2795
cudaGraphicsResource_t; 
#endif
#line 2800 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUexternalMemory_st *
#line 2800
cudaExternalMemory_t; 
#endif
#line 2805 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUexternalSemaphore_st *
#line 2805
cudaExternalSemaphore_t; 
#endif
#line 2810 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUgraph_st *
#line 2810
cudaGraph_t; 
#endif
#line 2815 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUgraphNode_st *
#line 2815
cudaGraphNode_t; 
#endif
#line 2820 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUuserObject_st *
#line 2820
cudaUserObject_t; 
#endif
#line 2825 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUfunc_st *
#line 2825
cudaFunction_t; 
#endif
#line 2830 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef struct CUmemPoolHandle_st *
#line 2830
cudaMemPool_t; 
#endif
#line 2835 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2835
enum cudaCGScope { 
#line 2836
cudaCGScopeInvalid, 
#line 2837
cudaCGScopeGrid, 
#line 2838
cudaCGScopeMultiGrid
#line 2839
}; 
#endif
#line 2844 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2844
struct cudaLaunchParams { 
#line 2846
void *func; 
#line 2847
dim3 gridDim; 
#line 2848
dim3 blockDim; 
#line 2849
void **args; 
#line 2850
size_t sharedMem; 
#line 2851
cudaStream_t stream; 
#line 2852
}; 
#endif
#line 2857 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2857
struct cudaKernelNodeParams { 
#line 2858
void *func; 
#line 2859
dim3 gridDim; 
#line 2860
dim3 blockDim; 
#line 2861
unsigned sharedMemBytes; 
#line 2862
void **kernelParams; 
#line 2863
void **extra; 
#line 2864
}; 
#endif
#line 2869 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2869
struct cudaExternalSemaphoreSignalNodeParams { 
#line 2870
cudaExternalSemaphore_t *extSemArray; 
#line 2871
const cudaExternalSemaphoreSignalParams *paramsArray; 
#line 2872
unsigned numExtSems; 
#line 2873
}; 
#endif
#line 2878 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2878
struct cudaExternalSemaphoreWaitNodeParams { 
#line 2879
cudaExternalSemaphore_t *extSemArray; 
#line 2880
const cudaExternalSemaphoreWaitParams *paramsArray; 
#line 2881
unsigned numExtSems; 
#line 2882
}; 
#endif
#line 2887 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2887
enum cudaGraphNodeType { 
#line 2888
cudaGraphNodeTypeKernel, 
#line 2889
cudaGraphNodeTypeMemcpy, 
#line 2890
cudaGraphNodeTypeMemset, 
#line 2891
cudaGraphNodeTypeHost, 
#line 2892
cudaGraphNodeTypeGraph, 
#line 2893
cudaGraphNodeTypeEmpty, 
#line 2894
cudaGraphNodeTypeWaitEvent, 
#line 2895
cudaGraphNodeTypeEventRecord, 
#line 2896
cudaGraphNodeTypeExtSemaphoreSignal, 
#line 2897
cudaGraphNodeTypeExtSemaphoreWait, 
#line 2898
cudaGraphNodeTypeMemAlloc, 
#line 2899
cudaGraphNodeTypeMemFree, 
#line 2900
cudaGraphNodeTypeCount
#line 2901
}; 
#endif
#line 2906 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
typedef struct CUgraphExec_st *cudaGraphExec_t; 
#line 2911
#if 0
#line 2911
enum cudaGraphExecUpdateResult { 
#line 2912
cudaGraphExecUpdateSuccess, 
#line 2913
cudaGraphExecUpdateError, 
#line 2914
cudaGraphExecUpdateErrorTopologyChanged, 
#line 2915
cudaGraphExecUpdateErrorNodeTypeChanged, 
#line 2916
cudaGraphExecUpdateErrorFunctionChanged, 
#line 2917
cudaGraphExecUpdateErrorParametersChanged, 
#line 2918
cudaGraphExecUpdateErrorNotSupported, 
#line 2919
cudaGraphExecUpdateErrorUnsupportedFunctionChange, 
#line 2920
cudaGraphExecUpdateErrorAttributesChanged
#line 2921
}; 
#endif
#line 2932 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 2926
enum cudaGraphInstantiateResult { 
#line 2927
cudaGraphInstantiateSuccess, 
#line 2928
cudaGraphInstantiateError, 
#line 2929
cudaGraphInstantiateInvalidStructure, 
#line 2930
cudaGraphInstantiateNodeOperationNotSupported, 
#line 2931
cudaGraphInstantiateMultipleDevicesNotSupported
#line 2932
} cudaGraphInstantiateResult; 
#endif
#line 2943 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 2937
struct cudaGraphInstantiateParams_st { 
#line 2939
unsigned __int64 flags; 
#line 2940
cudaStream_t uploadStream; 
#line 2941
cudaGraphNode_t errNode_out; 
#line 2942
cudaGraphInstantiateResult result_out; 
#line 2943
} cudaGraphInstantiateParams; 
#endif
#line 2965 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 2948
struct cudaGraphExecUpdateResultInfo_st { 
#line 2952
cudaGraphExecUpdateResult result; 
#line 2959
cudaGraphNode_t errorNode; 
#line 2964
cudaGraphNode_t errorFromNode; 
#line 2965
} cudaGraphExecUpdateResultInfo; 
#endif
#line 2971 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2971
enum cudaGetDriverEntryPointFlags { 
#line 2972
cudaEnableDefault, 
#line 2973
cudaEnableLegacyStream, 
#line 2974
cudaEnablePerThreadDefaultStream
#line 2975
}; 
#endif
#line 2980 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2980
enum cudaDriverEntryPointQueryResult { 
#line 2981
cudaDriverEntryPointSuccess, 
#line 2982
cudaDriverEntryPointSymbolNotFound, 
#line 2983
cudaDriverEntryPointVersionNotSufficent
#line 2984
}; 
#endif
#line 2989 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 2989
enum cudaGraphDebugDotFlags { 
#line 2990
cudaGraphDebugDotFlagsVerbose = (1 << 0), 
#line 2991
cudaGraphDebugDotFlagsKernelNodeParams = (1 << 2), 
#line 2992
cudaGraphDebugDotFlagsMemcpyNodeParams = (1 << 3), 
#line 2993
cudaGraphDebugDotFlagsMemsetNodeParams = (1 << 4), 
#line 2994
cudaGraphDebugDotFlagsHostNodeParams = (1 << 5), 
#line 2995
cudaGraphDebugDotFlagsEventNodeParams = (1 << 6), 
#line 2996
cudaGraphDebugDotFlagsExtSemasSignalNodeParams = (1 << 7), 
#line 2997
cudaGraphDebugDotFlagsExtSemasWaitNodeParams = (1 << 8), 
#line 2998
cudaGraphDebugDotFlagsKernelNodeAttributes = (1 << 9), 
#line 2999
cudaGraphDebugDotFlagsHandles = (1 << 10)
#line 3000
}; 
#endif
#line 3005 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
#line 3005
enum cudaGraphInstantiateFlags { 
#line 3006
cudaGraphInstantiateFlagAutoFreeOnLaunch = 1, 
#line 3007
cudaGraphInstantiateFlagUpload, 
#line 3008
cudaGraphInstantiateFlagDeviceLaunch = 4, 
#line 3009
cudaGraphInstantiateFlagUseNodePriority = 8
#line 3011
}; 
#endif
#line 3016 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3013
enum cudaLaunchMemSyncDomain { 
#line 3014
cudaLaunchMemSyncDomainDefault, 
#line 3015
cudaLaunchMemSyncDomainRemote
#line 3016
} cudaLaunchMemSyncDomain; 
#endif
#line 3021 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3018
struct cudaLaunchMemSyncDomainMap_st { 
#line 3019
unsigned char default_; 
#line 3020
unsigned char remote; 
#line 3021
} cudaLaunchMemSyncDomainMap; 
#endif
#line 3067 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3026
enum cudaLaunchAttributeID { 
#line 3027
cudaLaunchAttributeIgnore, 
#line 3028
cudaLaunchAttributeAccessPolicyWindow, 
#line 3029
cudaLaunchAttributeCooperative, 
#line 3030
cudaLaunchAttributeSynchronizationPolicy, 
#line 3031
cudaLaunchAttributeClusterDimension, 
#line 3032
cudaLaunchAttributeClusterSchedulingPolicyPreference, 
#line 3033
cudaLaunchAttributeProgrammaticStreamSerialization, 
#line 3044
cudaLaunchAttributeProgrammaticEvent, 
#line 3064
cudaLaunchAttributePriority, 
#line 3065
cudaLaunchAttributeMemSyncDomainMap, 
#line 3066
cudaLaunchAttributeMemSyncDomain
#line 3067
} cudaLaunchAttributeID; 
#endif
#line 3092 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3072
union cudaLaunchAttributeValue { 
#line 3073
char pad[64]; 
#line 3074
cudaAccessPolicyWindow accessPolicyWindow; 
#line 3075
int cooperative; 
#line 3076
cudaSynchronizationPolicy syncPolicy; 
#line 3077
struct { 
#line 3078
unsigned x; 
#line 3079
unsigned y; 
#line 3080
unsigned z; 
#line 3081
} clusterDim; 
#line 3082
cudaClusterSchedulingPolicy clusterSchedulingPolicyPreference; 
#line 3083
int programmaticStreamSerializationAllowed; 
#line 3084
struct { 
#line 3085
cudaEvent_t event; 
#line 3086
int flags; 
#line 3087
int triggerAtBlockStart; 
#line 3088
} programmaticEvent; 
#line 3089
int priority; 
#line 3090
cudaLaunchMemSyncDomainMap memSyncDomainMap; 
#line 3091
cudaLaunchMemSyncDomain memSyncDomain; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 3092
} cudaLaunchAttributeValue; 
#endif
#line 3101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3097
struct cudaLaunchAttribute_st { 
#line 3098
cudaLaunchAttributeID id; 
#line 3099
char pad[(8) - sizeof(cudaLaunchAttributeID)]; 
#line 3100
cudaLaunchAttributeValue val; 
#line 3101
} cudaLaunchAttribute; 
#endif
#line 3113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_types.h"
#if 0
typedef 
#line 3106
struct cudaLaunchConfig_st { 
#line 3107
dim3 gridDim; 
#line 3108
dim3 blockDim; 
#line 3109
size_t dynamicSmemBytes; 
#line 3110
cudaStream_t stream; 
#line 3111
cudaLaunchAttribute *attrs; 
#line 3112
unsigned numAttrs; __pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)__pad__(volatile char:8;)
#line 3113
} cudaLaunchConfig_t; 
#endif
#line 84 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_types.h"
#if 0
#line 84
enum cudaSurfaceBoundaryMode { 
#line 86
cudaBoundaryModeZero, 
#line 87
cudaBoundaryModeClamp, 
#line 88
cudaBoundaryModeTrap
#line 89
}; 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_types.h"
#if 0
#line 94
enum cudaSurfaceFormatMode { 
#line 96
cudaFormatModeForced, 
#line 97
cudaFormatModeAuto
#line 98
}; 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_types.h"
#if 0
typedef unsigned __int64 
#line 103
cudaSurfaceObject_t; 
#endif
#line 84 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_types.h"
#if 0
#line 84
enum cudaTextureAddressMode { 
#line 86
cudaAddressModeWrap, 
#line 87
cudaAddressModeClamp, 
#line 88
cudaAddressModeMirror, 
#line 89
cudaAddressModeBorder
#line 90
}; 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_types.h"
#if 0
#line 95
enum cudaTextureFilterMode { 
#line 97
cudaFilterModePoint, 
#line 98
cudaFilterModeLinear
#line 99
}; 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_types.h"
#if 0
#line 104
enum cudaTextureReadMode { 
#line 106
cudaReadModeElementType, 
#line 107
cudaReadModeNormalizedFloat
#line 108
}; 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_types.h"
#if 0
#line 113
struct cudaTextureDesc { 
#line 118
cudaTextureAddressMode addressMode[3]; 
#line 122
cudaTextureFilterMode filterMode; 
#line 126
cudaTextureReadMode readMode; 
#line 130
int sRGB; 
#line 134
float borderColor[4]; 
#line 138
int normalizedCoords; 
#line 142
unsigned maxAnisotropy; 
#line 146
cudaTextureFilterMode mipmapFilterMode; 
#line 150
float mipmapLevelBias; 
#line 154
float minMipmapLevelClamp; 
#line 158
float maxMipmapLevelClamp; 
#line 162
int disableTrilinearOptimization; 
#line 166
int seamlessCubemap; 
#line 167
}; 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_types.h"
#if 0
typedef unsigned __int64 
#line 172
cudaTextureObject_t; 
#endif
#line 87 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\library_types.h"
typedef 
#line 55
enum cudaDataType_t { 
#line 57
CUDA_R_16F = 2, 
#line 58
CUDA_C_16F = 6, 
#line 59
CUDA_R_16BF = 14, 
#line 60
CUDA_C_16BF, 
#line 61
CUDA_R_32F = 0, 
#line 62
CUDA_C_32F = 4, 
#line 63
CUDA_R_64F = 1, 
#line 64
CUDA_C_64F = 5, 
#line 65
CUDA_R_4I = 16, 
#line 66
CUDA_C_4I, 
#line 67
CUDA_R_4U, 
#line 68
CUDA_C_4U, 
#line 69
CUDA_R_8I = 3, 
#line 70
CUDA_C_8I = 7, 
#line 71
CUDA_R_8U, 
#line 72
CUDA_C_8U, 
#line 73
CUDA_R_16I = 20, 
#line 74
CUDA_C_16I, 
#line 75
CUDA_R_16U, 
#line 76
CUDA_C_16U, 
#line 77
CUDA_R_32I = 10, 
#line 78
CUDA_C_32I, 
#line 79
CUDA_R_32U, 
#line 80
CUDA_C_32U, 
#line 81
CUDA_R_64I = 24, 
#line 82
CUDA_C_64I, 
#line 83
CUDA_R_64U, 
#line 84
CUDA_C_64U, 
#line 85
CUDA_R_8F_E4M3, 
#line 86
CUDA_R_8F_E5M2
#line 87
} cudaDataType; 
#line 95
typedef 
#line 90
enum libraryPropertyType_t { 
#line 92
MAJOR_VERSION, 
#line 93
MINOR_VERSION, 
#line 94
PATCH_LEVEL
#line 95
} libraryPropertyType; 
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_malloc.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 58 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_malloc.h"
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 59
_calloc_base(size_t _Count, size_t _Size); 
#line 65
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 66
calloc(size_t _Count, size_t _Size); 
#line 72
int __cdecl _callnewh(size_t _Size); 
#line 77
__declspec(allocator) void *__cdecl 
#line 78
_expand(void * _Block, size_t _Size); 
#line 84
void __cdecl _free_base(void * _Block); 
#line 89
void __cdecl free(void * _Block); 
#line 94
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 95
_malloc_base(size_t _Size); 
#line 100
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 101
malloc(size_t _Size); 
#line 107
size_t __cdecl _msize_base(void * _Block) noexcept; 
#line 113
size_t __cdecl _msize(void * _Block); 
#line 118
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 119
_realloc_base(void * _Block, size_t _Size); 
#line 125
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 126
realloc(void * _Block, size_t _Size); 
#line 132
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 133
_recalloc_base(void * _Block, size_t _Count, size_t _Size); 
#line 140
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 141
_recalloc(void * _Block, size_t _Count, size_t _Size); 
#line 148
void __cdecl _aligned_free(void * _Block); 
#line 153
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 154
_aligned_malloc(size_t _Size, size_t _Alignment); 
#line 160
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 161
_aligned_offset_malloc(size_t _Size, size_t _Alignment, size_t _Offset); 
#line 169
size_t __cdecl _aligned_msize(void * _Block, size_t _Alignment, size_t _Offset); 
#line 176
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 177
_aligned_offset_realloc(void * _Block, size_t _Size, size_t _Alignment, size_t _Offset); 
#line 185
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 186
_aligned_offset_recalloc(void * _Block, size_t _Count, size_t _Size, size_t _Alignment, size_t _Offset); 
#line 195
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 196
_aligned_realloc(void * _Block, size_t _Size, size_t _Alignment); 
#line 203
__declspec(allocator) __declspec(restrict) void *__cdecl 
#line 204
_aligned_recalloc(void * _Block, size_t _Count, size_t _Size, size_t _Alignment); 
#line 232 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_malloc.h"
}__pragma( pack ( pop )) 
#line 234
#pragma warning(pop)
#line 16 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_search.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 20
__pragma( pack ( push, 8 )) extern "C" {
#line 23
typedef int (__cdecl *_CoreCrtSecureSearchSortCompareFunction)(void *, const void *, const void *); 
#line 24
typedef int (__cdecl *_CoreCrtNonSecureSearchSortCompareFunction)(const void *, const void *); 
#line 30
void *__cdecl bsearch_s(const void * _Key, const void * _Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 39
void __cdecl qsort_s(void * _Base, rsize_t _NumOfElements, rsize_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 52 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_search.h"
void *__cdecl bsearch(const void * _Key, const void * _Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 60
void __cdecl qsort(void * _Base, size_t _NumOfElements, size_t _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 68
void *__cdecl _lfind_s(const void * _Key, const void * _Base, unsigned * _NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 78
void *__cdecl _lfind(const void * _Key, const void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 87
void *__cdecl _lsearch_s(const void * _Key, void * _Base, unsigned * _NumOfElements, size_t _SizeOfElements, _CoreCrtSecureSearchSortCompareFunction _CompareFunction, void * _Context); 
#line 97
void *__cdecl _lsearch(const void * _Key, void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 195 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_search.h"
void *__cdecl lfind(const void * _Key, const void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 204
void *__cdecl lsearch(const void * _Key, void * _Base, unsigned * _NumOfElements, unsigned _SizeOfElements, _CoreCrtNonSecureSearchSortCompareFunction _CompareFunction); 
#line 216 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_search.h"
}__pragma( pack ( pop )) 
#line 218
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 54
errno_t __cdecl _itow_s(int _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 61
extern "C++" {template < size_t _Size > inline errno_t __cdecl _itow_s ( int _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _itow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 68 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _itow(int _Value, __wchar_t * _Buffer, int _Radix); 
#line 77 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _ltow_s(long _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 84
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ltow_s ( long _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ltow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 91 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _ltow(long _Value, __wchar_t * _Buffer, int _Radix); 
#line 99 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _ultow_s(unsigned long _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 106
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ultow_s ( unsigned long _Value, wchar_t ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ultow_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 113 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
__wchar_t *__cdecl _ultow(unsigned long _Value, __wchar_t * _Buffer, int _Radix); 
#line 121 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
double __cdecl wcstod(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 127
double __cdecl _wcstod_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 134
long __cdecl wcstol(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 141
long __cdecl _wcstol_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 149
__int64 __cdecl wcstoll(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 156
__int64 __cdecl _wcstoll_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 164
unsigned long __cdecl wcstoul(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 171
unsigned long __cdecl _wcstoul_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 179
unsigned __int64 __cdecl wcstoull(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 186
unsigned __int64 __cdecl _wcstoull_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 194
long double __cdecl wcstold(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 200
long double __cdecl _wcstold_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 207
float __cdecl wcstof(const __wchar_t * _String, __wchar_t ** _EndPtr); 
#line 213
float __cdecl _wcstof_l(const __wchar_t * _String, __wchar_t ** _EndPtr, _locale_t _Locale); 
#line 220
double __cdecl _wtof(const __wchar_t * _String); 
#line 225
double __cdecl _wtof_l(const __wchar_t * _String, _locale_t _Locale); 
#line 231
int __cdecl _wtoi(const __wchar_t * _String); 
#line 236
int __cdecl _wtoi_l(const __wchar_t * _String, _locale_t _Locale); 
#line 242
long __cdecl _wtol(const __wchar_t * _String); 
#line 247
long __cdecl _wtol_l(const __wchar_t * _String, _locale_t _Locale); 
#line 253
__int64 __cdecl _wtoll(const __wchar_t * _String); 
#line 258
__int64 __cdecl _wtoll_l(const __wchar_t * _String, _locale_t _Locale); 
#line 264
errno_t __cdecl _i64tow_s(__int64 _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 272
__wchar_t *__cdecl _i64tow(__int64 _Value, __wchar_t * _Buffer, int _Radix); 
#line 279
errno_t __cdecl _ui64tow_s(unsigned __int64 _Value, __wchar_t * _Buffer, size_t _BufferCount, int _Radix); 
#line 287
__wchar_t *__cdecl _ui64tow(unsigned __int64 _Value, __wchar_t * _Buffer, int _Radix); 
#line 294
__int64 __cdecl _wtoi64(const __wchar_t * _String); 
#line 299
__int64 __cdecl _wtoi64_l(const __wchar_t * _String, _locale_t _Locale); 
#line 305
__int64 __cdecl _wcstoi64(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 312
__int64 __cdecl _wcstoi64_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 320
unsigned __int64 __cdecl _wcstoui64(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix); 
#line 327
unsigned __int64 __cdecl _wcstoui64_l(const __wchar_t * _String, __wchar_t ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 339
__declspec(allocator) __wchar_t *__cdecl _wfullpath(__wchar_t * _Buffer, const __wchar_t * _Path, size_t _BufferCount); 
#line 348
errno_t __cdecl _wmakepath_s(__wchar_t * _Buffer, size_t _BufferCount, const __wchar_t * _Drive, const __wchar_t * _Dir, const __wchar_t * _Filename, const __wchar_t * _Ext); 
#line 357
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wmakepath_s ( wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _Drive, wchar_t const * _Dir, wchar_t const * _Filename, wchar_t const * _Ext ) throw ( ) { return _wmakepath_s ( _Buffer, _Size, _Drive, _Dir, _Filename, _Ext ); }}
#line 366 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wmakepath(__wchar_t * _Buffer, const __wchar_t * _Drive, const __wchar_t * _Dir, const __wchar_t * _Filename, const __wchar_t * _Ext); 
#line 375 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wperror(const __wchar_t * _ErrorMessage); 
#line 380
void __cdecl _wsplitpath(const __wchar_t * _FullPath, __wchar_t * _Drive, __wchar_t * _Dir, __wchar_t * _Filename, __wchar_t * _Ext); 
#line 388
errno_t __cdecl _wsplitpath_s(const __wchar_t * _FullPath, __wchar_t * _Drive, size_t _DriveCount, __wchar_t * _Dir, size_t _DirCount, __wchar_t * _Filename, size_t _FilenameCount, __wchar_t * _Ext, size_t _ExtCount); 
#line 400
extern "C++" {template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _wsplitpath_s ( wchar_t const * _Path, wchar_t ( & _Drive ) [ _DriveSize ], wchar_t ( & _Dir ) [ _DirSize ], wchar_t ( & _Name ) [ _NameSize ], wchar_t ( & _Ext ) [ _ExtSize ] ) throw ( ) { return _wsplitpath_s ( _Path, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }}
#line 409 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
errno_t __cdecl _wdupenv_s(__wchar_t ** _Buffer, size_t * _BufferCount, const __wchar_t * _VarName); 
#line 418
__wchar_t *__cdecl _wgetenv(const __wchar_t * _VarName); 
#line 424
errno_t __cdecl _wgetenv_s(size_t * _RequiredCount, __wchar_t * _Buffer, size_t _BufferCount, const __wchar_t * _VarName); 
#line 431
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wgetenv_s ( size_t * _RequiredCount, wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _VarName ) throw ( ) { return _wgetenv_s ( _RequiredCount, _Buffer, _Size, _VarName ); }}
#line 440 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
int __cdecl _wputenv(const __wchar_t * _EnvString); 
#line 445
errno_t __cdecl _wputenv_s(const __wchar_t * _Name, const __wchar_t * _Value); 
#line 450
errno_t __cdecl _wsearchenv_s(const __wchar_t * _Filename, const __wchar_t * _VarName, __wchar_t * _Buffer, size_t _BufferCount); 
#line 457
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wsearchenv_s ( wchar_t const * _Filename, wchar_t const * _VarName, wchar_t ( & _ResultPath ) [ _Size ] ) throw ( ) { return _wsearchenv_s ( _Filename, _VarName, _ResultPath, _Size ); }}
#line 464 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
void __cdecl _wsearchenv(const __wchar_t * _Filename, const __wchar_t * _VarName, __wchar_t * _ResultPath); 
#line 471 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
int __cdecl _wsystem(const __wchar_t * _Command); 
#line 479 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstdlib.h"
}__pragma( pack ( pop )) 
#line 481
#pragma warning(pop)
#line 18 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 22
__pragma( pack ( push, 8 )) extern "C" {
#line 38 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
void __cdecl _swab(char * _Buf1, char * _Buf2, int _SizeInBytes); 
#line 56
__declspec(noreturn) void __cdecl exit(int _Code); 
#line 57
__declspec(noreturn) void __cdecl _exit(int _Code); 
#line 58
__declspec(noreturn) void __cdecl _Exit(int _Code); 
#line 59
__declspec(noreturn) void __cdecl quick_exit(int _Code); 
#line 60
__declspec(noreturn) void __cdecl abort(); 
#line 67 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
unsigned __cdecl _set_abort_behavior(unsigned _Flags, unsigned _Mask); 
#line 77
typedef int (__cdecl *_onexit_t)(void); 
#line 144 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl atexit(void (__cdecl *)(void)); 
#line 145
_onexit_t __cdecl _onexit(_onexit_t _Func); 
#line 148 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl at_quick_exit(void (__cdecl *)(void)); 
#line 159
typedef void (__cdecl *_purecall_handler)(void); 
#line 162
typedef void (__cdecl *_invalid_parameter_handler)(const __wchar_t *, const __wchar_t *, const __wchar_t *, unsigned, uintptr_t); 
#line 171
_purecall_handler __cdecl _set_purecall_handler(_purecall_handler _Handler); 
#line 175
_purecall_handler __cdecl _get_purecall_handler(); 
#line 178
_invalid_parameter_handler __cdecl _set_invalid_parameter_handler(_invalid_parameter_handler _Handler); 
#line 182
_invalid_parameter_handler __cdecl _get_invalid_parameter_handler(); 
#line 184
_invalid_parameter_handler __cdecl _set_thread_local_invalid_parameter_handler(_invalid_parameter_handler _Handler); 
#line 188
_invalid_parameter_handler __cdecl _get_thread_local_invalid_parameter_handler(); 
#line 212 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl _set_error_mode(int _Mode); 
#line 217
int *__cdecl _errno(); 
#line 220
errno_t __cdecl _set_errno(int _Value); 
#line 221
errno_t __cdecl _get_errno(int * _Value); 
#line 223
unsigned long *__cdecl __doserrno(); 
#line 226
errno_t __cdecl _set_doserrno(unsigned long _Value); 
#line 227
errno_t __cdecl _get_doserrno(unsigned long * _Value); 
#line 230
char **__cdecl __sys_errlist(); 
#line 233
int *__cdecl __sys_nerr(); 
#line 236
void __cdecl perror(const char * _ErrMsg); 
#line 242 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char **__cdecl __p__pgmptr(); 
#line 243
__wchar_t **__cdecl __p__wpgmptr(); 
#line 244
int *__cdecl __p__fmode(); 
#line 259 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _get_pgmptr(char ** _Value); 
#line 262
errno_t __cdecl _get_wpgmptr(__wchar_t ** _Value); 
#line 264
errno_t __cdecl _set_fmode(int _Mode); 
#line 266
errno_t __cdecl _get_fmode(int * _PMode); 
#line 279
typedef 
#line 275
struct _div_t { 
#line 277
int quot; 
#line 278
int rem; 
#line 279
} div_t; 
#line 285
typedef 
#line 281
struct _ldiv_t { 
#line 283
long quot; 
#line 284
long rem; 
#line 285
} ldiv_t; 
#line 291
typedef 
#line 287
struct _lldiv_t { 
#line 289
__int64 quot; 
#line 290
__int64 rem; 
#line 291
} lldiv_t; 
#line 293
int __cdecl abs(int _Number); 
#line 294
long __cdecl labs(long _Number); 
#line 295
__int64 __cdecl llabs(__int64 _Number); 
#line 296
__int64 __cdecl _abs64(__int64 _Number); 
#line 298
unsigned short __cdecl _byteswap_ushort(unsigned short _Number); 
#line 299
unsigned long __cdecl _byteswap_ulong(unsigned long _Number); 
#line 300
unsigned __int64 __cdecl _byteswap_uint64(unsigned __int64 _Number); 
#line 302
div_t __cdecl div(int _Numerator, int _Denominator); 
#line 303
ldiv_t __cdecl ldiv(long _Numerator, long _Denominator); 
#line 304
lldiv_t __cdecl lldiv(__int64 _Numerator, __int64 _Denominator); 
#line 308
#pragma warning(push)
#pragma warning(disable: 6540)
#line 311
unsigned __cdecl _rotl(unsigned _Value, int _Shift); 
#line 317
unsigned long __cdecl _lrotl(unsigned long _Value, int _Shift); 
#line 322
unsigned __int64 __cdecl _rotl64(unsigned __int64 _Value, int _Shift); 
#line 327
unsigned __cdecl _rotr(unsigned _Value, int _Shift); 
#line 333
unsigned long __cdecl _lrotr(unsigned long _Value, int _Shift); 
#line 338
unsigned __int64 __cdecl _rotr64(unsigned __int64 _Value, int _Shift); 
#line 343
#pragma warning(pop)
#line 350
void __cdecl srand(unsigned _Seed); 
#line 352
int __cdecl rand(); 
#line 361 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
extern "C++" {
#line 363
inline long abs(const long _X) throw() 
#line 364
{ 
#line 365
return labs(_X); 
#line 366
} 
#line 368
inline __int64 abs(const __int64 _X) throw() 
#line 369
{ 
#line 370
return llabs(_X); 
#line 371
} 
#line 373
inline ldiv_t div(const long _A1, const long _A2) throw() 
#line 374
{ 
#line 375
return ldiv(_A1, _A2); 
#line 376
} 
#line 378
inline lldiv_t div(const __int64 _A1, const __int64 _A2) throw() 
#line 379
{ 
#line 380
return lldiv(_A1, _A2); 
#line 381
} 
#line 382
}
#line 394 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
#pragma pack ( push, 4 )
#line 398
typedef 
#line 396
struct { 
#line 397
unsigned char ld[10]; 
#line 398
} _LDOUBLE; 
#pragma pack ( pop )
#line 418 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
typedef 
#line 416
struct { 
#line 417
double x; 
#line 418
} _CRT_DOUBLE; 
#line 423
typedef 
#line 421
struct { 
#line 422
float f; 
#line 423
} _CRT_FLOAT; 
#line 432
typedef 
#line 430
struct { 
#line 431
long double x; 
#line 432
} _LONGDOUBLE; 
#line 436
#pragma pack ( push, 4 )
#line 440
typedef 
#line 438
struct { 
#line 439
unsigned char ld12[12]; 
#line 440
} _LDBL12; 
#pragma pack ( pop )
#line 450
double __cdecl atof(const char * _String); 
#line 451
int __cdecl atoi(const char * _String); 
#line 452
long __cdecl atol(const char * _String); 
#line 453
__int64 __cdecl atoll(const char * _String); 
#line 454
__int64 __cdecl _atoi64(const char * _String); 
#line 456
double __cdecl _atof_l(const char * _String, _locale_t _Locale); 
#line 457
int __cdecl _atoi_l(const char * _String, _locale_t _Locale); 
#line 458
long __cdecl _atol_l(const char * _String, _locale_t _Locale); 
#line 459
__int64 __cdecl _atoll_l(const char * _String, _locale_t _Locale); 
#line 460
__int64 __cdecl _atoi64_l(const char * _String, _locale_t _Locale); 
#line 462
int __cdecl _atoflt(_CRT_FLOAT * _Result, const char * _String); 
#line 463
int __cdecl _atodbl(_CRT_DOUBLE * _Result, char * _String); 
#line 464
int __cdecl _atoldbl(_LDOUBLE * _Result, char * _String); 
#line 467
int __cdecl _atoflt_l(_CRT_FLOAT * _Result, const char * _String, _locale_t _Locale); 
#line 474
int __cdecl _atodbl_l(_CRT_DOUBLE * _Result, char * _String, _locale_t _Locale); 
#line 482
int __cdecl _atoldbl_l(_LDOUBLE * _Result, char * _String, _locale_t _Locale); 
#line 489
float __cdecl strtof(const char * _String, char ** _EndPtr); 
#line 495
float __cdecl _strtof_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 502
double __cdecl strtod(const char * _String, char ** _EndPtr); 
#line 508
double __cdecl _strtod_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 515
long double __cdecl strtold(const char * _String, char ** _EndPtr); 
#line 521
long double __cdecl _strtold_l(const char * _String, char ** _EndPtr, _locale_t _Locale); 
#line 528
long __cdecl strtol(const char * _String, char ** _EndPtr, int _Radix); 
#line 535
long __cdecl _strtol_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 543
__int64 __cdecl strtoll(const char * _String, char ** _EndPtr, int _Radix); 
#line 550
__int64 __cdecl _strtoll_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 558
unsigned long __cdecl strtoul(const char * _String, char ** _EndPtr, int _Radix); 
#line 565
unsigned long __cdecl _strtoul_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 573
unsigned __int64 __cdecl strtoull(const char * _String, char ** _EndPtr, int _Radix); 
#line 580
unsigned __int64 __cdecl _strtoull_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 588
__int64 __cdecl _strtoi64(const char * _String, char ** _EndPtr, int _Radix); 
#line 595
__int64 __cdecl _strtoi64_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 603
unsigned __int64 __cdecl _strtoui64(const char * _String, char ** _EndPtr, int _Radix); 
#line 610
unsigned __int64 __cdecl _strtoui64_l(const char * _String, char ** _EndPtr, int _Radix, _locale_t _Locale); 
#line 626
errno_t __cdecl _itoa_s(int _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 633
extern "C++" {template < size_t _Size > inline errno_t __cdecl _itoa_s ( int _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _itoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 641 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _itoa(int _Value, char * _Buffer, int _Radix); 
#line 650 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _ltoa_s(long _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 657
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ltoa_s ( long _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ltoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 664 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _ltoa(long _Value, char * _Buffer, int _Radix); 
#line 673 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _ultoa_s(unsigned long _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 680
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ultoa_s ( unsigned long _Value, char ( & _Buffer ) [ _Size ], int _Radix ) throw ( ) { return _ultoa_s ( _Value, _Buffer, _Size, _Radix ); }}
#line 687 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _ultoa(unsigned long _Value, char * _Buffer, int _Radix); 
#line 696 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _i64toa_s(__int64 _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 705
char *__cdecl _i64toa(__int64 _Value, char * _Buffer, int _Radix); 
#line 713
errno_t __cdecl _ui64toa_s(unsigned __int64 _Value, char * _Buffer, size_t _BufferCount, int _Radix); 
#line 721
char *__cdecl _ui64toa(unsigned __int64 _Value, char * _Buffer, int _Radix); 
#line 741
errno_t __cdecl _ecvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 750
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ecvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _DigitCount, int * _PtDec, int * _PtSign ) throw ( ) { return _ecvt_s ( _Buffer, _Size, _Value, _DigitCount, _PtDec, _PtSign ); }}
#line 760 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _ecvt(double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 769
errno_t __cdecl _fcvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 778
extern "C++" {template < size_t _Size > inline errno_t __cdecl _fcvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign ) throw ( ) { return _fcvt_s ( _Buffer, _Size, _Value, _FractionalDigitCount, _PtDec, _PtSign ); }}
#line 790 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _fcvt(double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 798
errno_t __cdecl _gcvt_s(char * _Buffer, size_t _BufferCount, double _Value, int _DigitCount); 
#line 805
extern "C++" {template < size_t _Size > inline errno_t __cdecl _gcvt_s ( char ( & _Buffer ) [ _Size ], double _Value, int _DigitCount ) throw ( ) { return _gcvt_s ( _Buffer, _Size, _Value, _DigitCount ); }}
#line 814 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl _gcvt(double _Value, int _DigitCount, char * _Buffer); 
#line 843 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl ___mb_cur_max_func(); 
#line 846
int __cdecl ___mb_cur_max_l_func(_locale_t _Locale); 
#line 852 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl mblen(const char * _Ch, size_t _MaxCount); 
#line 858
int __cdecl _mblen_l(const char * _Ch, size_t _MaxCount, _locale_t _Locale); 
#line 866
size_t __cdecl _mbstrlen(const char * _String); 
#line 872
size_t __cdecl _mbstrlen_l(const char * _String, _locale_t _Locale); 
#line 879
size_t __cdecl _mbstrnlen(const char * _String, size_t _MaxCount); 
#line 886
size_t __cdecl _mbstrnlen_l(const char * _String, size_t _MaxCount, _locale_t _Locale); 
#line 893
int __cdecl mbtowc(__wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes); 
#line 900
int __cdecl _mbtowc_l(__wchar_t * _DstCh, const char * _SrcCh, size_t _SrcSizeInBytes, _locale_t _Locale); 
#line 908
errno_t __cdecl mbstowcs_s(size_t * _PtNumOfCharConverted, __wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount); 
#line 916
extern "C++" {template < size_t _Size > inline errno_t __cdecl mbstowcs_s ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], char const * _Source, size_t _MaxCount ) throw ( ) { return mbstowcs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }}
#line 924 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
size_t __cdecl mbstowcs(__wchar_t * _Dest, const char * _Source, size_t _MaxCount); 
#line 932 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _mbstowcs_s_l(size_t * _PtNumOfCharConverted, __wchar_t * _DstBuf, size_t _SizeInWords, const char * _SrcBuf, size_t _MaxCount, _locale_t _Locale); 
#line 941
extern "C++" {template < size_t _Size > inline errno_t __cdecl _mbstowcs_s_l ( size_t * _PtNumOfCharConverted, wchar_t ( & _Dest ) [ _Size ], char const * _Source, size_t _MaxCount, _locale_t _Locale ) throw ( ) { return _mbstowcs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }}
#line 950 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
size_t __cdecl _mbstowcs_l(__wchar_t * _Dest, const char * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 963 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl wctomb(char * _MbCh, __wchar_t _WCh); 
#line 969
int __cdecl _wctomb_l(char * _MbCh, __wchar_t _WCh, _locale_t _Locale); 
#line 978
errno_t __cdecl wctomb_s(int * _SizeConverted, char * _MbCh, rsize_t _SizeInBytes, __wchar_t _WCh); 
#line 988 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _wctomb_s_l(int * _SizeConverted, char * _MbCh, size_t _SizeInBytes, __wchar_t _WCh, _locale_t _Locale); 
#line 996
errno_t __cdecl wcstombs_s(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const __wchar_t * _Src, size_t _MaxCountInBytes); 
#line 1004
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcstombs_s ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], wchar_t const * _Source, size_t _MaxCount ) throw ( ) { return wcstombs_s ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount ); }}
#line 1012 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
size_t __cdecl wcstombs(char * _Dest, const __wchar_t * _Source, size_t _MaxCount); 
#line 1020 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _wcstombs_s_l(size_t * _PtNumOfCharConverted, char * _Dst, size_t _DstSizeInBytes, const __wchar_t * _Src, size_t _MaxCountInBytes, _locale_t _Locale); 
#line 1029
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcstombs_s_l ( size_t * _PtNumOfCharConverted, char ( & _Dest ) [ _Size ], wchar_t const * _Source, size_t _MaxCount, _locale_t _Locale ) throw ( ) { return _wcstombs_s_l ( _PtNumOfCharConverted, _Dest, _Size, _Source, _MaxCount, _Locale ); }}
#line 1038 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
size_t __cdecl _wcstombs_l(char * _Dest, const __wchar_t * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 1068 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
__declspec(allocator) char *__cdecl _fullpath(char * _Buffer, const char * _Path, size_t _BufferCount); 
#line 1077
errno_t __cdecl _makepath_s(char * _Buffer, size_t _BufferCount, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext); 
#line 1086
extern "C++" {template < size_t _Size > inline errno_t __cdecl _makepath_s ( char ( & _Buffer ) [ _Size ], char const * _Drive, char const * _Dir, char const * _Filename, char const * _Ext ) throw ( ) { return _makepath_s ( _Buffer, _Size, _Drive, _Dir, _Filename, _Ext ); }}
#line 1095 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
void __cdecl _makepath(char * _Buffer, const char * _Drive, const char * _Dir, const char * _Filename, const char * _Ext); 
#line 1105 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
void __cdecl _splitpath(const char * _FullPath, char * _Drive, char * _Dir, char * _Filename, char * _Ext); 
#line 1114
errno_t __cdecl _splitpath_s(const char * _FullPath, char * _Drive, size_t _DriveCount, char * _Dir, size_t _DirCount, char * _Filename, size_t _FilenameCount, char * _Ext, size_t _ExtCount); 
#line 1126
extern "C++" {template < size_t _DriveSize, size_t _DirSize, size_t _NameSize, size_t _ExtSize > inline errno_t __cdecl _splitpath_s ( char const * _Dest, char ( & _Drive ) [ _DriveSize ], char ( & _Dir ) [ _DirSize ], char ( & _Name ) [ _NameSize ], char ( & _Ext ) [ _ExtSize ] ) throw ( ) { return _splitpath_s ( _Dest, _Drive, _DriveSize, _Dir, _DirSize, _Name, _NameSize, _Ext, _ExtSize ); }}
#line 1132
errno_t __cdecl getenv_s(size_t * _RequiredCount, char * _Buffer, rsize_t _BufferCount, const char * _VarName); 
#line 1144 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int *__cdecl __p___argc(); 
#line 1145
char ***__cdecl __p___argv(); 
#line 1146
__wchar_t ***__cdecl __p___wargv(); 
#line 1158 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char ***__cdecl __p__environ(); 
#line 1159
__wchar_t ***__cdecl __p__wenviron(); 
#line 1184 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
char *__cdecl getenv(const char * _VarName); 
#line 1188
extern "C++" {template < size_t _Size > inline errno_t __cdecl getenv_s ( size_t * _RequiredCount, char ( & _Buffer ) [ _Size ], char const * _VarName ) throw ( ) { return getenv_s ( _RequiredCount, _Buffer, _Size, _VarName ); }}
#line 1201 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
errno_t __cdecl _dupenv_s(char ** _Buffer, size_t * _BufferCount, const char * _VarName); 
#line 1211 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
int __cdecl system(const char * _Command); 
#line 1217
#pragma warning(push)
#pragma warning(disable: 6540)
#line 1221
int __cdecl _putenv(const char * _EnvString); 
#line 1226
errno_t __cdecl _putenv_s(const char * _Name, const char * _Value); 
#line 1231
#pragma warning(pop)
#line 1233
errno_t __cdecl _searchenv_s(const char * _Filename, const char * _VarName, char * _Buffer, size_t _BufferCount); 
#line 1240
extern "C++" {template < size_t _Size > inline errno_t __cdecl _searchenv_s ( char const * _Filename, char const * _VarName, char ( & _Buffer ) [ _Size ] ) throw ( ) { return _searchenv_s ( _Filename, _VarName, _Buffer, _Size ); }}
#line 1247 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
void __cdecl _searchenv(const char * _Filename, const char * _VarName, char * _Buffer); 
#line 1255 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetErrorMode in" "stead. See online help for details.")) void __cdecl 
#line 1256
_seterrormode(int _Mode); 
#line 1260
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Beep instead. S" "ee online help for details.")) void __cdecl 
#line 1261
_beep(unsigned _Frequency, unsigned _Duration); 
#line 1266
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using Sleep instead. " "See online help for details.")) void __cdecl 
#line 1267
_sleep(unsigned long _Duration); 
#line 1289 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
#pragma warning(push)
#pragma warning(disable: 4141)
#line 1293
char *__cdecl ecvt(double _Value, int _DigitCount, int * _PtDec, int * _PtSign); 
#line 1301
char *__cdecl fcvt(double _Value, int _FractionalDigitCount, int * _PtDec, int * _PtSign); 
#line 1309
char *__cdecl gcvt(double _Value, int _DigitCount, char * _DstBuf); 
#line 1316
char *__cdecl itoa(int _Value, char * _Buffer, int _Radix); 
#line 1323
char *__cdecl ltoa(long _Value, char * _Buffer, int _Radix); 
#line 1331
void __cdecl swab(char * _Buf1, char * _Buf2, int _SizeInBytes); 
#line 1338
char *__cdecl ultoa(unsigned long _Value, char * _Buffer, int _Radix); 
#line 1347
int __cdecl putenv(const char * _EnvString); 
#line 1351
#pragma warning(pop)
#line 1353
_onexit_t __cdecl onexit(_onexit_t _Func); 
#line 1359 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\stdlib.h"
}__pragma( pack ( pop )) 
#line 1361
#pragma warning(pop)
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
extern "C" {
#line 186
extern cudaError_t __stdcall __cudaDeviceSynchronizeDeprecationAvoidance(); 
#line 235
extern cudaError_t __stdcall __cudaCDP2DeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
#line 236
extern cudaError_t __stdcall __cudaCDP2DeviceGetLimit(size_t * pValue, cudaLimit limit); 
#line 237
extern cudaError_t __stdcall __cudaCDP2DeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
#line 238
extern cudaError_t __stdcall __cudaCDP2DeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
#line 239
extern cudaError_t __stdcall __cudaCDP2GetLastError(); 
#line 240
extern cudaError_t __stdcall __cudaCDP2PeekAtLastError(); 
#line 241
extern const char *__stdcall __cudaCDP2GetErrorString(cudaError_t error); 
#line 242
extern const char *__stdcall __cudaCDP2GetErrorName(cudaError_t error); 
#line 243
extern cudaError_t __stdcall __cudaCDP2GetDeviceCount(int * count); 
#line 244
extern cudaError_t __stdcall __cudaCDP2GetDevice(int * device); 
#line 245
extern cudaError_t __stdcall __cudaCDP2StreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
#line 246
extern cudaError_t __stdcall __cudaCDP2StreamDestroy(cudaStream_t stream); 
#line 247
extern cudaError_t __stdcall __cudaCDP2StreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
#line 248
extern cudaError_t __stdcall __cudaCDP2StreamWaitEvent_ptsz(cudaStream_t stream, cudaEvent_t event, unsigned flags); 
#line 249
extern cudaError_t __stdcall __cudaCDP2EventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
#line 250
extern cudaError_t __stdcall __cudaCDP2EventRecord(cudaEvent_t event, cudaStream_t stream); 
#line 251
extern cudaError_t __stdcall __cudaCDP2EventRecord_ptsz(cudaEvent_t event, cudaStream_t stream); 
#line 252
extern cudaError_t __stdcall __cudaCDP2EventRecordWithFlags(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
#line 253
extern cudaError_t __stdcall __cudaCDP2EventRecordWithFlags_ptsz(cudaEvent_t event, cudaStream_t stream, unsigned flags); 
#line 254
extern cudaError_t __stdcall __cudaCDP2EventDestroy(cudaEvent_t event); 
#line 255
extern cudaError_t __stdcall __cudaCDP2FuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
#line 256
extern cudaError_t __stdcall __cudaCDP2Free(void * devPtr); 
#line 257
extern cudaError_t __stdcall __cudaCDP2Malloc(void ** devPtr, size_t size); 
#line 258
extern cudaError_t __stdcall __cudaCDP2MemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
#line 259
extern cudaError_t __stdcall __cudaCDP2MemcpyAsync_ptsz(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream); 
#line 260
extern cudaError_t __stdcall __cudaCDP2Memcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
#line 261
extern cudaError_t __stdcall __cudaCDP2Memcpy2DAsync_ptsz(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream); 
#line 262
extern cudaError_t __stdcall __cudaCDP2Memcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream); 
#line 263
extern cudaError_t __stdcall __cudaCDP2Memcpy3DAsync_ptsz(const cudaMemcpy3DParms * p, cudaStream_t stream); 
#line 264
extern cudaError_t __stdcall __cudaCDP2MemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream); 
#line 265
extern cudaError_t __stdcall __cudaCDP2MemsetAsync_ptsz(void * devPtr, int value, size_t count, cudaStream_t stream); 
#line 266
extern cudaError_t __stdcall __cudaCDP2Memset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
#line 267
extern cudaError_t __stdcall __cudaCDP2Memset2DAsync_ptsz(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream); 
#line 268
extern cudaError_t __stdcall __cudaCDP2Memset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
#line 269
extern cudaError_t __stdcall __cudaCDP2Memset3DAsync_ptsz(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream); 
#line 270
extern cudaError_t __stdcall __cudaCDP2RuntimeGetVersion(int * runtimeVersion); 
#line 271
extern void *__stdcall __cudaCDP2GetParameterBuffer(size_t alignment, size_t size); 
#line 272
extern void *__stdcall __cudaCDP2GetParameterBufferV2(void * func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize); 
#line 273
extern cudaError_t __stdcall __cudaCDP2LaunchDevice_ptsz(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
#line 274
extern cudaError_t __stdcall __cudaCDP2LaunchDeviceV2_ptsz(void * parameterBuffer, cudaStream_t stream); 
#line 275
extern cudaError_t __stdcall __cudaCDP2LaunchDevice(void * func, void * parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream); 
#line 276
extern cudaError_t __stdcall __cudaCDP2LaunchDeviceV2(void * parameterBuffer, cudaStream_t stream); 
#line 277
extern cudaError_t __stdcall __cudaCDP2OccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize); 
#line 278
extern cudaError_t __stdcall __cudaCDP2OccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
#line 281
extern cudaError_t __stdcall cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 300 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static inline cudaGraphExec_t __stdcall cudaGetCurrentGraphExec() {int volatile ___ = 1;::exit(___);}
#if 0
#line 301
{ 
#line 302
unsigned __int64 current_graph_exec; 
#line 303
__asm mov.u64 %0, %%current_graph_exec;
return (cudaGraphExec_t)current_graph_exec; 
#line 305
} 
#endif
#line 323 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static inline void __stdcall cudaTriggerProgrammaticLaunchCompletion() {int volatile ___ = 1;::exit(___);}
#if 0
#line 324
{ 
#line 325
__asm griddepcontrol.launch_dependents;
} 
#endif
#line 339 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static inline void __stdcall cudaGridDependencySynchronize() {int volatile ___ = 1;::exit(___);}
#if 0
#line 340
{ 
#line 341
__asm griddepcontrol.wait;
} 
#endif
#line 346 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
extern unsigned __int64 __stdcall cudaCGGetIntrinsicHandle(cudaCGScope scope); 
#line 347
extern cudaError_t __stdcall cudaCGSynchronize(unsigned __int64 handle, unsigned flags); 
#line 348
extern cudaError_t __stdcall cudaCGSynchronizeGrid(unsigned __int64 handle, unsigned flags); 
#line 349
extern cudaError_t __stdcall cudaCGGetSize(unsigned * numThreads, unsigned * numGrids, unsigned __int64 handle); 
#line 350
extern cudaError_t __stdcall cudaCGGetRank(unsigned * threadRank, unsigned * gridRank, unsigned __int64 handle); 
#line 572
static __inline void *__stdcall cudaGetParameterBuffer(size_t alignment, size_t size) {int volatile ___ = 1;(void)alignment;(void)size;::exit(___);}
#if 0
#line 573
{ 
#line 574
return __cudaCDP2GetParameterBuffer(alignment, size); 
#line 575
} 
#endif
#line 608 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static __inline void *__stdcall cudaGetParameterBufferV2(void *func, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize) {int volatile ___ = 1;(void)func;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;::exit(___);}
#if 0
#line 609
{ 
#line 610
return __cudaCDP2GetParameterBufferV2(func, gridDimension, blockDimension, sharedMemSize); 
#line 611
} 
#endif
#line 618 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDevice_ptsz(void *func, void *parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream) {int volatile ___ = 1;(void)func;(void)parameterBuffer;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;(void)stream;::exit(___);}
#if 0
#line 619
{ 
#line 620
return __cudaCDP2LaunchDevice_ptsz(func, parameterBuffer, gridDimension, blockDimension, sharedMemSize, stream); 
#line 621
} 
#endif
#line 623 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDeviceV2_ptsz(void *parameterBuffer, cudaStream_t stream) {int volatile ___ = 1;(void)parameterBuffer;(void)stream;::exit(___);}
#if 0
#line 624
{ 
#line 625
return __cudaCDP2LaunchDeviceV2_ptsz(parameterBuffer, stream); 
#line 626
} 
#endif
#line 658 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDevice(void *func, void *parameterBuffer, dim3 gridDimension, dim3 blockDimension, unsigned sharedMemSize, cudaStream_t stream) {int volatile ___ = 1;(void)func;(void)parameterBuffer;(void)gridDimension;(void)blockDimension;(void)sharedMemSize;(void)stream;::exit(___);}
#if 0
#line 659
{ 
#line 660
return __cudaCDP2LaunchDevice(func, parameterBuffer, gridDimension, blockDimension, sharedMemSize, stream); 
#line 661
} 
#endif
#line 663 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
static __inline cudaError_t __stdcall cudaLaunchDeviceV2(void *parameterBuffer, cudaStream_t stream) {int volatile ___ = 1;(void)parameterBuffer;(void)stream;::exit(___);}
#if 0
#line 664
{ 
#line 665
return __cudaCDP2LaunchDeviceV2(parameterBuffer, stream); 
#line 666
} 
#endif
#line 720 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_device_runtime_api.h"
}
#line 722
template< class T> static __inline cudaError_t cudaMalloc(T ** devPtr, size_t size); 
#line 723
template< class T> static __inline cudaError_t cudaFuncGetAttributes(cudaFuncAttributes * attr, T * entry); 
#line 724
template< class T> static __inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize); 
#line 725
template< class T> static __inline cudaError_t cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, T func, int blockSize, size_t dynamicSmemSize, unsigned flags); 
#line 271 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern "C" {
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceReset(); 
#line 333
extern cudaError_t __stdcall cudaDeviceSynchronize(); 
#line 419
extern cudaError_t __stdcall cudaDeviceSetLimit(cudaLimit limit, size_t value); 
#line 455
extern cudaError_t __stdcall cudaDeviceGetLimit(size_t * pValue, cudaLimit limit); 
#line 478
extern cudaError_t __stdcall cudaDeviceGetTexture1DLinearMaxWidth(size_t * maxWidthInElements, const cudaChannelFormatDesc * fmtDesc, int device); 
#line 512 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGetCacheConfig(cudaFuncCache * pCacheConfig); 
#line 549
extern cudaError_t __stdcall cudaDeviceGetStreamPriorityRange(int * leastPriority, int * greatestPriority); 
#line 593
extern cudaError_t __stdcall cudaDeviceSetCacheConfig(cudaFuncCache cacheConfig); 
#line 624
extern cudaError_t __stdcall cudaDeviceGetSharedMemConfig(cudaSharedMemConfig * pConfig); 
#line 668
extern cudaError_t __stdcall cudaDeviceSetSharedMemConfig(cudaSharedMemConfig config); 
#line 695
extern cudaError_t __stdcall cudaDeviceGetByPCIBusId(int * device, const char * pciBusId); 
#line 725
extern cudaError_t __stdcall cudaDeviceGetPCIBusId(char * pciBusId, int len, int device); 
#line 775
extern cudaError_t __stdcall cudaIpcGetEventHandle(cudaIpcEventHandle_t * handle, cudaEvent_t event); 
#line 818
extern cudaError_t __stdcall cudaIpcOpenEventHandle(cudaEvent_t * event, cudaIpcEventHandle_t handle); 
#line 862
extern cudaError_t __stdcall cudaIpcGetMemHandle(cudaIpcMemHandle_t * handle, void * devPtr); 
#line 928
extern cudaError_t __stdcall cudaIpcOpenMemHandle(void ** devPtr, cudaIpcMemHandle_t handle, unsigned flags); 
#line 966
extern cudaError_t __stdcall cudaIpcCloseMemHandle(void * devPtr); 
#line 998
extern cudaError_t __stdcall cudaDeviceFlushGPUDirectRDMAWrites(cudaFlushGPUDirectRDMAWritesTarget target, cudaFlushGPUDirectRDMAWritesScope scope); 
#line 1041 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadExit(); 
#line 1067
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadSynchronize(); 
#line 1116
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadSetLimit(cudaLimit limit, size_t value); 
#line 1149
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadGetLimit(size_t * pValue, cudaLimit limit); 
#line 1185
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadGetCacheConfig(cudaFuncCache * pCacheConfig); 
#line 1232
__declspec(deprecated) extern cudaError_t __stdcall cudaThreadSetCacheConfig(cudaFuncCache cacheConfig); 
#line 1297
extern cudaError_t __stdcall cudaGetLastError(); 
#line 1348
extern cudaError_t __stdcall cudaPeekAtLastError(); 
#line 1364
extern const char *__stdcall cudaGetErrorName(cudaError_t error); 
#line 1380
extern const char *__stdcall cudaGetErrorString(cudaError_t error); 
#line 1409
extern cudaError_t __stdcall cudaGetDeviceCount(int * count); 
#line 1714
extern cudaError_t __stdcall cudaGetDeviceProperties_v2(cudaDeviceProp * prop, int device); 
#line 1916
extern cudaError_t __stdcall cudaDeviceGetAttribute(int * value, cudaDeviceAttr attr, int device); 
#line 1934
extern cudaError_t __stdcall cudaDeviceGetDefaultMemPool(cudaMemPool_t * memPool, int device); 
#line 1958
extern cudaError_t __stdcall cudaDeviceSetMemPool(int device, cudaMemPool_t memPool); 
#line 1978
extern cudaError_t __stdcall cudaDeviceGetMemPool(cudaMemPool_t * memPool, int device); 
#line 2026
extern cudaError_t __stdcall cudaDeviceGetNvSciSyncAttributes(void * nvSciSyncAttrList, int device, int flags); 
#line 2066
extern cudaError_t __stdcall cudaDeviceGetP2PAttribute(int * value, cudaDeviceP2PAttr attr, int srcDevice, int dstDevice); 
#line 2088
extern cudaError_t __stdcall cudaChooseDevice(int * device, const cudaDeviceProp * prop); 
#line 2117
extern cudaError_t __stdcall cudaInitDevice(int device, unsigned deviceFlags, unsigned flags); 
#line 2163
extern cudaError_t __stdcall cudaSetDevice(int device); 
#line 2185
extern cudaError_t __stdcall cudaGetDevice(int * device); 
#line 2216
extern cudaError_t __stdcall cudaSetValidDevices(int * device_arr, int len); 
#line 2282
extern cudaError_t __stdcall cudaSetDeviceFlags(unsigned flags); 
#line 2327
extern cudaError_t __stdcall cudaGetDeviceFlags(unsigned * flags); 
#line 2367
extern cudaError_t __stdcall cudaStreamCreate(cudaStream_t * pStream); 
#line 2399
extern cudaError_t __stdcall cudaStreamCreateWithFlags(cudaStream_t * pStream, unsigned flags); 
#line 2445
extern cudaError_t __stdcall cudaStreamCreateWithPriority(cudaStream_t * pStream, unsigned flags, int priority); 
#line 2472
extern cudaError_t __stdcall cudaStreamGetPriority(cudaStream_t hStream, int * priority); 
#line 2497
extern cudaError_t __stdcall cudaStreamGetFlags(cudaStream_t hStream, unsigned * flags); 
#line 2532
extern cudaError_t __stdcall cudaStreamGetId(cudaStream_t hStream, unsigned __int64 * streamId); 
#line 2547
extern cudaError_t __stdcall cudaCtxResetPersistingL2Cache(); 
#line 2567
extern cudaError_t __stdcall cudaStreamCopyAttributes(cudaStream_t dst, cudaStream_t src); 
#line 2588
extern cudaError_t __stdcall cudaStreamGetAttribute(cudaStream_t hStream, cudaLaunchAttributeID attr, cudaLaunchAttributeValue * value_out); 
#line 2612
extern cudaError_t __stdcall cudaStreamSetAttribute(cudaStream_t hStream, cudaLaunchAttributeID attr, const cudaLaunchAttributeValue * value); 
#line 2646
extern cudaError_t __stdcall cudaStreamDestroy(cudaStream_t stream); 
#line 2677
extern cudaError_t __stdcall cudaStreamWaitEvent(cudaStream_t stream, cudaEvent_t event, unsigned flags = 0); 
#line 2685
typedef void (__stdcall *cudaStreamCallback_t)(cudaStream_t stream, cudaError_t status, void * userData); 
#line 2752
extern cudaError_t __stdcall cudaStreamAddCallback(cudaStream_t stream, cudaStreamCallback_t callback, void * userData, unsigned flags); 
#line 2776
extern cudaError_t __stdcall cudaStreamSynchronize(cudaStream_t stream); 
#line 2801
extern cudaError_t __stdcall cudaStreamQuery(cudaStream_t stream); 
#line 2885
extern cudaError_t __stdcall cudaStreamAttachMemAsync(cudaStream_t stream, void * devPtr, size_t length = 0, unsigned flags = 4); 
#line 2924 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaStreamBeginCapture(cudaStream_t stream, cudaStreamCaptureMode mode); 
#line 2975
extern cudaError_t __stdcall cudaThreadExchangeStreamCaptureMode(cudaStreamCaptureMode * mode); 
#line 3003
extern cudaError_t __stdcall cudaStreamEndCapture(cudaStream_t stream, cudaGraph_t * pGraph); 
#line 3041
extern cudaError_t __stdcall cudaStreamIsCapturing(cudaStream_t stream, cudaStreamCaptureStatus * pCaptureStatus); 
#line 3089
extern cudaError_t __stdcall cudaStreamGetCaptureInfo_v2(cudaStream_t stream, cudaStreamCaptureStatus * captureStatus_out, unsigned __int64 * id_out = 0, cudaGraph_t * graph_out = 0, const cudaGraphNode_t ** dependencies_out = 0, size_t * numDependencies_out = 0); 
#line 3121
extern cudaError_t __stdcall cudaStreamUpdateCaptureDependencies(cudaStream_t stream, cudaGraphNode_t * dependencies, size_t numDependencies, unsigned flags = 0); 
#line 3158
extern cudaError_t __stdcall cudaEventCreate(cudaEvent_t * event); 
#line 3195
extern cudaError_t __stdcall cudaEventCreateWithFlags(cudaEvent_t * event, unsigned flags); 
#line 3235
extern cudaError_t __stdcall cudaEventRecord(cudaEvent_t event, cudaStream_t stream = 0); 
#line 3282
extern cudaError_t __stdcall cudaEventRecordWithFlags(cudaEvent_t event, cudaStream_t stream = 0, unsigned flags = 0); 
#line 3314 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaEventQuery(cudaEvent_t event); 
#line 3344
extern cudaError_t __stdcall cudaEventSynchronize(cudaEvent_t event); 
#line 3373
extern cudaError_t __stdcall cudaEventDestroy(cudaEvent_t event); 
#line 3417
extern cudaError_t __stdcall cudaEventElapsedTime(float * ms, cudaEvent_t start, cudaEvent_t end); 
#line 3598
extern cudaError_t __stdcall cudaImportExternalMemory(cudaExternalMemory_t * extMem_out, const cudaExternalMemoryHandleDesc * memHandleDesc); 
#line 3653
extern cudaError_t __stdcall cudaExternalMemoryGetMappedBuffer(void ** devPtr, cudaExternalMemory_t extMem, const cudaExternalMemoryBufferDesc * bufferDesc); 
#line 3713
extern cudaError_t __stdcall cudaExternalMemoryGetMappedMipmappedArray(cudaMipmappedArray_t * mipmap, cudaExternalMemory_t extMem, const cudaExternalMemoryMipmappedArrayDesc * mipmapDesc); 
#line 3737
extern cudaError_t __stdcall cudaDestroyExternalMemory(cudaExternalMemory_t extMem); 
#line 3891
extern cudaError_t __stdcall cudaImportExternalSemaphore(cudaExternalSemaphore_t * extSem_out, const cudaExternalSemaphoreHandleDesc * semHandleDesc); 
#line 3974
extern cudaError_t __stdcall cudaSignalExternalSemaphoresAsync_v2(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreSignalParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
#line 4050
extern cudaError_t __stdcall cudaWaitExternalSemaphoresAsync_v2(const cudaExternalSemaphore_t * extSemArray, const cudaExternalSemaphoreWaitParams * paramsArray, unsigned numExtSems, cudaStream_t stream = 0); 
#line 4073
extern cudaError_t __stdcall cudaDestroyExternalSemaphore(cudaExternalSemaphore_t extSem); 
#line 4140
extern cudaError_t __stdcall cudaLaunchKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 4202
extern cudaError_t __stdcall cudaLaunchKernelExC(const cudaLaunchConfig_t * config, const void * func, void ** args); 
#line 4259
extern cudaError_t __stdcall cudaLaunchCooperativeKernel(const void * func, dim3 gridDim, dim3 blockDim, void ** args, size_t sharedMem, cudaStream_t stream); 
#line 4360
__declspec(deprecated) extern cudaError_t __stdcall cudaLaunchCooperativeKernelMultiDevice(cudaLaunchParams * launchParamsList, unsigned numDevices, unsigned flags = 0); 
#line 4405
extern cudaError_t __stdcall cudaFuncSetCacheConfig(const void * func, cudaFuncCache cacheConfig); 
#line 4460
extern cudaError_t __stdcall cudaFuncSetSharedMemConfig(const void * func, cudaSharedMemConfig config); 
#line 4493
extern cudaError_t __stdcall cudaFuncGetAttributes(cudaFuncAttributes * attr, const void * func); 
#line 4530
extern cudaError_t __stdcall cudaFuncSetAttribute(const void * func, cudaFuncAttribute attr, int value); 
#line 4554
__declspec(deprecated) extern cudaError_t __stdcall cudaSetDoubleForDevice(double * d); 
#line 4578
__declspec(deprecated) extern cudaError_t __stdcall cudaSetDoubleForHost(double * d); 
#line 4644
extern cudaError_t __stdcall cudaLaunchHostFunc(cudaStream_t stream, cudaHostFn_t fn, void * userData); 
#line 4701
extern cudaError_t __stdcall cudaOccupancyMaxActiveBlocksPerMultiprocessor(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize); 
#line 4730
extern cudaError_t __stdcall cudaOccupancyAvailableDynamicSMemPerBlock(size_t * dynamicSmemSize, const void * func, int numBlocks, int blockSize); 
#line 4775
extern cudaError_t __stdcall cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int * numBlocks, const void * func, int blockSize, size_t dynamicSMemSize, unsigned flags); 
#line 4810
extern cudaError_t __stdcall cudaOccupancyMaxPotentialClusterSize(int * clusterSize, const void * func, const cudaLaunchConfig_t * launchConfig); 
#line 4849
extern cudaError_t __stdcall cudaOccupancyMaxActiveClusters(int * numClusters, const void * func, const cudaLaunchConfig_t * launchConfig); 
#line 4969
extern cudaError_t __stdcall cudaMallocManaged(void ** devPtr, size_t size, unsigned flags = 1); 
#line 5002 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMalloc(void ** devPtr, size_t size); 
#line 5035
extern cudaError_t __stdcall cudaMallocHost(void ** ptr, size_t size); 
#line 5078
extern cudaError_t __stdcall cudaMallocPitch(void ** devPtr, size_t * pitch, size_t width, size_t height); 
#line 5130
extern cudaError_t __stdcall cudaMallocArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, size_t width, size_t height = 0, unsigned flags = 0); 
#line 5168
extern cudaError_t __stdcall cudaFree(void * devPtr); 
#line 5191
extern cudaError_t __stdcall cudaFreeHost(void * ptr); 
#line 5214
extern cudaError_t __stdcall cudaFreeArray(cudaArray_t array); 
#line 5237
extern cudaError_t __stdcall cudaFreeMipmappedArray(cudaMipmappedArray_t mipmappedArray); 
#line 5303
extern cudaError_t __stdcall cudaHostAlloc(void ** pHost, size_t size, unsigned flags); 
#line 5396
extern cudaError_t __stdcall cudaHostRegister(void * ptr, size_t size, unsigned flags); 
#line 5419
extern cudaError_t __stdcall cudaHostUnregister(void * ptr); 
#line 5464
extern cudaError_t __stdcall cudaHostGetDevicePointer(void ** pDevice, void * pHost, unsigned flags); 
#line 5486
extern cudaError_t __stdcall cudaHostGetFlags(unsigned * pFlags, void * pHost); 
#line 5525
extern cudaError_t __stdcall cudaMalloc3D(cudaPitchedPtr * pitchedDevPtr, cudaExtent extent); 
#line 5670
extern cudaError_t __stdcall cudaMalloc3DArray(cudaArray_t * array, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned flags = 0); 
#line 5815
extern cudaError_t __stdcall cudaMallocMipmappedArray(cudaMipmappedArray_t * mipmappedArray, const cudaChannelFormatDesc * desc, cudaExtent extent, unsigned numLevels, unsigned flags = 0); 
#line 5848
extern cudaError_t __stdcall cudaGetMipmappedArrayLevel(cudaArray_t * levelArray, cudaMipmappedArray_const_t mipmappedArray, unsigned level); 
#line 5953
extern cudaError_t __stdcall cudaMemcpy3D(const cudaMemcpy3DParms * p); 
#line 5985
extern cudaError_t __stdcall cudaMemcpy3DPeer(const cudaMemcpy3DPeerParms * p); 
#line 6103
extern cudaError_t __stdcall cudaMemcpy3DAsync(const cudaMemcpy3DParms * p, cudaStream_t stream = 0); 
#line 6130
extern cudaError_t __stdcall cudaMemcpy3DPeerAsync(const cudaMemcpy3DPeerParms * p, cudaStream_t stream = 0); 
#line 6164
extern cudaError_t __stdcall cudaMemGetInfo(size_t * free, size_t * total); 
#line 6190
extern cudaError_t __stdcall cudaArrayGetInfo(cudaChannelFormatDesc * desc, cudaExtent * extent, unsigned * flags, cudaArray_t array); 
#line 6219
extern cudaError_t __stdcall cudaArrayGetPlane(cudaArray_t * pPlaneArray, cudaArray_t hArray, unsigned planeIdx); 
#line 6242
extern cudaError_t __stdcall cudaArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaArray_t array, int device); 
#line 6266
extern cudaError_t __stdcall cudaMipmappedArrayGetMemoryRequirements(cudaArrayMemoryRequirements * memoryRequirements, cudaMipmappedArray_t mipmap, int device); 
#line 6294
extern cudaError_t __stdcall cudaArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaArray_t array); 
#line 6324 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMipmappedArrayGetSparseProperties(cudaArraySparseProperties * sparseProperties, cudaMipmappedArray_t mipmap); 
#line 6369 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaMemcpy(void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 6404
extern cudaError_t __stdcall cudaMemcpyPeer(void * dst, int dstDevice, const void * src, int srcDevice, size_t count); 
#line 6453
extern cudaError_t __stdcall cudaMemcpy2D(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6503
extern cudaError_t __stdcall cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6553
extern cudaError_t __stdcall cudaMemcpy2DFromArray(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind); 
#line 6600
extern cudaError_t __stdcall cudaMemcpy2DArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t width, size_t height, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
#line 6643
extern cudaError_t __stdcall cudaMemcpyToSymbol(const void * symbol, const void * src, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyHostToDevice); 
#line 6686
extern cudaError_t __stdcall cudaMemcpyFromSymbol(void * dst, const void * symbol, size_t count, size_t offset = 0, cudaMemcpyKind kind = cudaMemcpyDeviceToHost); 
#line 6743
extern cudaError_t __stdcall cudaMemcpyAsync(void * dst, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6778
extern cudaError_t __stdcall cudaMemcpyPeerAsync(void * dst, int dstDevice, const void * src, int srcDevice, size_t count, cudaStream_t stream = 0); 
#line 6841
extern cudaError_t __stdcall cudaMemcpy2DAsync(void * dst, size_t dpitch, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6899
extern cudaError_t __stdcall cudaMemcpy2DToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t spitch, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 6956
extern cudaError_t __stdcall cudaMemcpy2DFromArrayAsync(void * dst, size_t dpitch, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t width, size_t height, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7007
extern cudaError_t __stdcall cudaMemcpyToSymbolAsync(const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7058
extern cudaError_t __stdcall cudaMemcpyFromSymbolAsync(void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7087
extern cudaError_t __stdcall cudaMemset(void * devPtr, int value, size_t count); 
#line 7121
extern cudaError_t __stdcall cudaMemset2D(void * devPtr, size_t pitch, int value, size_t width, size_t height); 
#line 7167
extern cudaError_t __stdcall cudaMemset3D(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent); 
#line 7203
extern cudaError_t __stdcall cudaMemsetAsync(void * devPtr, int value, size_t count, cudaStream_t stream = 0); 
#line 7244
extern cudaError_t __stdcall cudaMemset2DAsync(void * devPtr, size_t pitch, int value, size_t width, size_t height, cudaStream_t stream = 0); 
#line 7297
extern cudaError_t __stdcall cudaMemset3DAsync(cudaPitchedPtr pitchedDevPtr, int value, cudaExtent extent, cudaStream_t stream = 0); 
#line 7325
extern cudaError_t __stdcall cudaGetSymbolAddress(void ** devPtr, const void * symbol); 
#line 7352
extern cudaError_t __stdcall cudaGetSymbolSize(size_t * size, const void * symbol); 
#line 7422
extern cudaError_t __stdcall cudaMemPrefetchAsync(const void * devPtr, size_t count, int dstDevice, cudaStream_t stream = 0); 
#line 7538
extern cudaError_t __stdcall cudaMemAdvise(const void * devPtr, size_t count, cudaMemoryAdvise advice, int device); 
#line 7597
extern cudaError_t __stdcall cudaMemRangeGetAttribute(void * data, size_t dataSize, cudaMemRangeAttribute attribute, const void * devPtr, size_t count); 
#line 7636
extern cudaError_t __stdcall cudaMemRangeGetAttributes(void ** data, size_t * dataSizes, cudaMemRangeAttribute * attributes, size_t numAttributes, const void * devPtr, size_t count); 
#line 7696
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind); 
#line 7738
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyFromArray(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind); 
#line 7781
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyArrayToArray(cudaArray_t dst, size_t wOffsetDst, size_t hOffsetDst, cudaArray_const_t src, size_t wOffsetSrc, size_t hOffsetSrc, size_t count, cudaMemcpyKind kind = cudaMemcpyDeviceToDevice); 
#line 7832
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyToArrayAsync(cudaArray_t dst, size_t wOffset, size_t hOffset, const void * src, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7882
__declspec(deprecated) extern cudaError_t __stdcall cudaMemcpyFromArrayAsync(void * dst, cudaArray_const_t src, size_t wOffset, size_t hOffset, size_t count, cudaMemcpyKind kind, cudaStream_t stream = 0); 
#line 7951
extern cudaError_t __stdcall cudaMallocAsync(void ** devPtr, size_t size, cudaStream_t hStream); 
#line 7977
extern cudaError_t __stdcall cudaFreeAsync(void * devPtr, cudaStream_t hStream); 
#line 8002
extern cudaError_t __stdcall cudaMemPoolTrimTo(cudaMemPool_t memPool, size_t minBytesToKeep); 
#line 8046
extern cudaError_t __stdcall cudaMemPoolSetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
#line 8094
extern cudaError_t __stdcall cudaMemPoolGetAttribute(cudaMemPool_t memPool, cudaMemPoolAttr attr, void * value); 
#line 8109
extern cudaError_t __stdcall cudaMemPoolSetAccess(cudaMemPool_t memPool, const cudaMemAccessDesc * descList, size_t count); 
#line 8122
extern cudaError_t __stdcall cudaMemPoolGetAccess(cudaMemAccessFlags * flags, cudaMemPool_t memPool, cudaMemLocation * location); 
#line 8142
extern cudaError_t __stdcall cudaMemPoolCreate(cudaMemPool_t * memPool, const cudaMemPoolProps * poolProps); 
#line 8164
extern cudaError_t __stdcall cudaMemPoolDestroy(cudaMemPool_t memPool); 
#line 8200
extern cudaError_t __stdcall cudaMallocFromPoolAsync(void ** ptr, size_t size, cudaMemPool_t memPool, cudaStream_t stream); 
#line 8225
extern cudaError_t __stdcall cudaMemPoolExportToShareableHandle(void * shareableHandle, cudaMemPool_t memPool, cudaMemAllocationHandleType handleType, unsigned flags); 
#line 8252
extern cudaError_t __stdcall cudaMemPoolImportFromShareableHandle(cudaMemPool_t * memPool, void * shareableHandle, cudaMemAllocationHandleType handleType, unsigned flags); 
#line 8275
extern cudaError_t __stdcall cudaMemPoolExportPointer(cudaMemPoolPtrExportData * exportData, void * ptr); 
#line 8304
extern cudaError_t __stdcall cudaMemPoolImportPointer(void ** ptr, cudaMemPool_t memPool, cudaMemPoolPtrExportData * exportData); 
#line 8457
extern cudaError_t __stdcall cudaPointerGetAttributes(cudaPointerAttributes * attributes, const void * ptr); 
#line 8498
extern cudaError_t __stdcall cudaDeviceCanAccessPeer(int * canAccessPeer, int device, int peerDevice); 
#line 8540
extern cudaError_t __stdcall cudaDeviceEnablePeerAccess(int peerDevice, unsigned flags); 
#line 8562
extern cudaError_t __stdcall cudaDeviceDisablePeerAccess(int peerDevice); 
#line 8626
extern cudaError_t __stdcall cudaGraphicsUnregisterResource(cudaGraphicsResource_t resource); 
#line 8661
extern cudaError_t __stdcall cudaGraphicsResourceSetMapFlags(cudaGraphicsResource_t resource, unsigned flags); 
#line 8700
extern cudaError_t __stdcall cudaGraphicsMapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
#line 8735
extern cudaError_t __stdcall cudaGraphicsUnmapResources(int count, cudaGraphicsResource_t * resources, cudaStream_t stream = 0); 
#line 8767
extern cudaError_t __stdcall cudaGraphicsResourceGetMappedPointer(void ** devPtr, size_t * size, cudaGraphicsResource_t resource); 
#line 8805
extern cudaError_t __stdcall cudaGraphicsSubResourceGetMappedArray(cudaArray_t * array, cudaGraphicsResource_t resource, unsigned arrayIndex, unsigned mipLevel); 
#line 8834
extern cudaError_t __stdcall cudaGraphicsResourceGetMappedMipmappedArray(cudaMipmappedArray_t * mipmappedArray, cudaGraphicsResource_t resource); 
#line 8869
extern cudaError_t __stdcall cudaGetChannelDesc(cudaChannelFormatDesc * desc, cudaArray_const_t array); 
#line 8899
extern cudaChannelFormatDesc __stdcall cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f); 
#line 9123
extern cudaError_t __stdcall cudaCreateTextureObject(cudaTextureObject_t * pTexObject, const cudaResourceDesc * pResDesc, const cudaTextureDesc * pTexDesc, const cudaResourceViewDesc * pResViewDesc); 
#line 9143
extern cudaError_t __stdcall cudaDestroyTextureObject(cudaTextureObject_t texObject); 
#line 9163
extern cudaError_t __stdcall cudaGetTextureObjectResourceDesc(cudaResourceDesc * pResDesc, cudaTextureObject_t texObject); 
#line 9183
extern cudaError_t __stdcall cudaGetTextureObjectTextureDesc(cudaTextureDesc * pTexDesc, cudaTextureObject_t texObject); 
#line 9204
extern cudaError_t __stdcall cudaGetTextureObjectResourceViewDesc(cudaResourceViewDesc * pResViewDesc, cudaTextureObject_t texObject); 
#line 9249
extern cudaError_t __stdcall cudaCreateSurfaceObject(cudaSurfaceObject_t * pSurfObject, const cudaResourceDesc * pResDesc); 
#line 9269
extern cudaError_t __stdcall cudaDestroySurfaceObject(cudaSurfaceObject_t surfObject); 
#line 9288
extern cudaError_t __stdcall cudaGetSurfaceObjectResourceDesc(cudaResourceDesc * pResDesc, cudaSurfaceObject_t surfObject); 
#line 9322
extern cudaError_t __stdcall cudaDriverGetVersion(int * driverVersion); 
#line 9351
extern cudaError_t __stdcall cudaRuntimeGetVersion(int * runtimeVersion); 
#line 9398
extern cudaError_t __stdcall cudaGraphCreate(cudaGraph_t * pGraph, unsigned flags); 
#line 9495
extern cudaError_t __stdcall cudaGraphAddKernelNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaKernelNodeParams * pNodeParams); 
#line 9528
extern cudaError_t __stdcall cudaGraphKernelNodeGetParams(cudaGraphNode_t node, cudaKernelNodeParams * pNodeParams); 
#line 9553
extern cudaError_t __stdcall cudaGraphKernelNodeSetParams(cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
#line 9573
extern cudaError_t __stdcall cudaGraphKernelNodeCopyAttributes(cudaGraphNode_t hSrc, cudaGraphNode_t hDst); 
#line 9596
extern cudaError_t __stdcall cudaGraphKernelNodeGetAttribute(cudaGraphNode_t hNode, cudaLaunchAttributeID attr, cudaLaunchAttributeValue * value_out); 
#line 9620
extern cudaError_t __stdcall cudaGraphKernelNodeSetAttribute(cudaGraphNode_t hNode, cudaLaunchAttributeID attr, const cudaLaunchAttributeValue * value); 
#line 9670
extern cudaError_t __stdcall cudaGraphAddMemcpyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemcpy3DParms * pCopyParams); 
#line 9729
extern cudaError_t __stdcall cudaGraphAddMemcpyNodeToSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 9798 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemcpyNodeFromSymbol(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 9866 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemcpyNode1D(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 9898 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeGetParams(cudaGraphNode_t node, cudaMemcpy3DParms * pNodeParams); 
#line 9924
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParams(cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
#line 9963
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParamsToSymbol(cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 10009 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParamsFromSymbol(cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 10055 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemcpyNodeSetParams1D(cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 10102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemsetNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaMemsetParams * pMemsetParams); 
#line 10125
extern cudaError_t __stdcall cudaGraphMemsetNodeGetParams(cudaGraphNode_t node, cudaMemsetParams * pNodeParams); 
#line 10148
extern cudaError_t __stdcall cudaGraphMemsetNodeSetParams(cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
#line 10189
extern cudaError_t __stdcall cudaGraphAddHostNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaHostNodeParams * pNodeParams); 
#line 10212
extern cudaError_t __stdcall cudaGraphHostNodeGetParams(cudaGraphNode_t node, cudaHostNodeParams * pNodeParams); 
#line 10235
extern cudaError_t __stdcall cudaGraphHostNodeSetParams(cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
#line 10275
extern cudaError_t __stdcall cudaGraphAddChildGraphNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaGraph_t childGraph); 
#line 10302
extern cudaError_t __stdcall cudaGraphChildGraphNodeGetGraph(cudaGraphNode_t node, cudaGraph_t * pGraph); 
#line 10339
extern cudaError_t __stdcall cudaGraphAddEmptyNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies); 
#line 10382
extern cudaError_t __stdcall cudaGraphAddEventRecordNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
#line 10409 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventRecordNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
#line 10436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventRecordNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
#line 10482 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddEventWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaEvent_t event); 
#line 10509 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventWaitNodeGetEvent(cudaGraphNode_t node, cudaEvent_t * event_out); 
#line 10536 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphEventWaitNodeSetEvent(cudaGraphNode_t node, cudaEvent_t event); 
#line 10585 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddExternalSemaphoresSignalNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 10618 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresSignalNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreSignalNodeParams * params_out); 
#line 10645 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresSignalNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 10694 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddExternalSemaphoresWaitNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 10727 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresWaitNodeGetParams(cudaGraphNode_t hNode, cudaExternalSemaphoreWaitNodeParams * params_out); 
#line 10754 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExternalSemaphoresWaitNodeSetParams(cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 10831 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemAllocNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, cudaMemAllocNodeParams * nodeParams); 
#line 10858 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemAllocNodeGetParams(cudaGraphNode_t node, cudaMemAllocNodeParams * params_out); 
#line 10918 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphAddMemFreeNode(cudaGraphNode_t * pGraphNode, cudaGraph_t graph, const cudaGraphNode_t * pDependencies, size_t numDependencies, void * dptr); 
#line 10942 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphMemFreeNodeGetParams(cudaGraphNode_t node, void * dptr_out); 
#line 10970 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGraphMemTrim(int device); 
#line 11007 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceGetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value); 
#line 11041 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaDeviceSetGraphMemAttribute(int device, cudaGraphMemAttributeType attr, void * value); 
#line 11069 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphClone(cudaGraph_t * pGraphClone, cudaGraph_t originalGraph); 
#line 11097
extern cudaError_t __stdcall cudaGraphNodeFindInClone(cudaGraphNode_t * pNode, cudaGraphNode_t originalNode, cudaGraph_t clonedGraph); 
#line 11128
extern cudaError_t __stdcall cudaGraphNodeGetType(cudaGraphNode_t node, cudaGraphNodeType * pType); 
#line 11159
extern cudaError_t __stdcall cudaGraphGetNodes(cudaGraph_t graph, cudaGraphNode_t * nodes, size_t * numNodes); 
#line 11190
extern cudaError_t __stdcall cudaGraphGetRootNodes(cudaGraph_t graph, cudaGraphNode_t * pRootNodes, size_t * pNumRootNodes); 
#line 11224
extern cudaError_t __stdcall cudaGraphGetEdges(cudaGraph_t graph, cudaGraphNode_t * from, cudaGraphNode_t * to, size_t * numEdges); 
#line 11255
extern cudaError_t __stdcall cudaGraphNodeGetDependencies(cudaGraphNode_t node, cudaGraphNode_t * pDependencies, size_t * pNumDependencies); 
#line 11287
extern cudaError_t __stdcall cudaGraphNodeGetDependentNodes(cudaGraphNode_t node, cudaGraphNode_t * pDependentNodes, size_t * pNumDependentNodes); 
#line 11318
extern cudaError_t __stdcall cudaGraphAddDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, size_t numDependencies); 
#line 11349
extern cudaError_t __stdcall cudaGraphRemoveDependencies(cudaGraph_t graph, const cudaGraphNode_t * from, const cudaGraphNode_t * to, size_t numDependencies); 
#line 11379
extern cudaError_t __stdcall cudaGraphDestroyNode(cudaGraphNode_t node); 
#line 11441
extern cudaError_t __stdcall cudaGraphInstantiate(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, unsigned __int64 flags = 0); 
#line 11512
extern cudaError_t __stdcall cudaGraphInstantiateWithFlags(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, unsigned __int64 flags = 0); 
#line 11617 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphInstantiateWithParams(cudaGraphExec_t * pGraphExec, cudaGraph_t graph, cudaGraphInstantiateParams * instantiateParams); 
#line 11642
extern cudaError_t __stdcall cudaGraphExecGetFlags(cudaGraphExec_t graphExec, unsigned __int64 * flags); 
#line 11693
extern cudaError_t __stdcall cudaGraphExecKernelNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaKernelNodeParams * pNodeParams); 
#line 11743
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemcpy3DParms * pNodeParams); 
#line 11798
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParamsToSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const void * symbol, const void * src, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 11861 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParamsFromSymbol(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * symbol, size_t count, size_t offset, cudaMemcpyKind kind); 
#line 11922 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemcpyNodeSetParams1D(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, void * dst, const void * src, size_t count, cudaMemcpyKind kind); 
#line 11976 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecMemsetNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaMemsetParams * pNodeParams); 
#line 12015
extern cudaError_t __stdcall cudaGraphExecHostNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, const cudaHostNodeParams * pNodeParams); 
#line 12061
extern cudaError_t __stdcall cudaGraphExecChildGraphNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t node, cudaGraph_t childGraph); 
#line 12105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecEventRecordNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
#line 12149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecEventWaitNodeSetEvent(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, cudaEvent_t event); 
#line 12196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecExternalSemaphoresSignalNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreSignalNodeParams * nodeParams); 
#line 12243 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecExternalSemaphoresWaitNodeSetParams(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, const cudaExternalSemaphoreWaitNodeParams * nodeParams); 
#line 12283 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphNodeSetEnabled(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, unsigned isEnabled); 
#line 12317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphNodeGetEnabled(cudaGraphExec_t hGraphExec, cudaGraphNode_t hNode, unsigned * isEnabled); 
#line 12402 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphExecUpdateResultInfo * resultInfo); 
#line 12427
extern cudaError_t __stdcall cudaGraphUpload(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 12458 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGraphLaunch(cudaGraphExec_t graphExec, cudaStream_t stream); 
#line 12481
extern cudaError_t __stdcall cudaGraphExecDestroy(cudaGraphExec_t graphExec); 
#line 12502
extern cudaError_t __stdcall cudaGraphDestroy(cudaGraph_t graph); 
#line 12521
extern cudaError_t __stdcall cudaGraphDebugDotPrint(cudaGraph_t graph, const char * path, unsigned flags); 
#line 12557
extern cudaError_t __stdcall cudaUserObjectCreate(cudaUserObject_t * object_out, void * ptr, cudaHostFn_t destroy, unsigned initialRefcount, unsigned flags); 
#line 12581
extern cudaError_t __stdcall cudaUserObjectRetain(cudaUserObject_t object, unsigned count = 1); 
#line 12609
extern cudaError_t __stdcall cudaUserObjectRelease(cudaUserObject_t object, unsigned count = 1); 
#line 12637
extern cudaError_t __stdcall cudaGraphRetainUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1, unsigned flags = 0); 
#line 12662
extern cudaError_t __stdcall cudaGraphReleaseUserObject(cudaGraph_t graph, cudaUserObject_t object, unsigned count = 1); 
#line 12740
extern cudaError_t __stdcall cudaGetDriverEntryPoint(const char * symbol, void ** funcPtr, unsigned __int64 flags, cudaDriverEntryPointQueryResult * driverStatus = 0); 
#line 12748 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
extern cudaError_t __stdcall cudaGetExportTable(const void ** ppExportTable, const cudaUUID_t * pExportTableId); 
#line 12927
extern cudaError_t cudaGetFuncBySymbol(cudaFunction_t * functionPtr, const void * symbolPtr); 
#line 13088 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\cuda_runtime_api.h"
}
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\channel_descriptor.h"
template< class T> __inline ::cudaChannelFormatDesc cudaCreateChannelDesc() 
#line 118
{ 
#line 119
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
#line 120
} 
#line 122
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf() 
#line 123
{ 
#line 124
int e = (((int)sizeof(unsigned short)) * 8); 
#line 126
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 127
} 
#line 129
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf1() 
#line 130
{ 
#line 131
int e = (((int)sizeof(unsigned short)) * 8); 
#line 133
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 134
} 
#line 136
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf2() 
#line 137
{ 
#line 138
int e = (((int)sizeof(unsigned short)) * 8); 
#line 140
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
#line 141
} 
#line 143
static __inline cudaChannelFormatDesc cudaCreateChannelDescHalf4() 
#line 144
{ 
#line 145
int e = (((int)sizeof(unsigned short)) * 8); 
#line 147
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
#line 148
} 
#line 150
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char> () 
#line 151
{ 
#line 152
int e = (((int)sizeof(char)) * 8); 
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\channel_descriptor.h"
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\channel_descriptor.h"
} 
#line 161
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< signed char> () 
#line 162
{ 
#line 163
int e = (((int)sizeof(signed char)) * 8); 
#line 165
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 166
} 
#line 168
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned char> () 
#line 169
{ 
#line 170
int e = (((int)sizeof(unsigned char)) * 8); 
#line 172
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 173
} 
#line 175
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char1> () 
#line 176
{ 
#line 177
int e = (((int)sizeof(signed char)) * 8); 
#line 179
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 180
} 
#line 182
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar1> () 
#line 183
{ 
#line 184
int e = (((int)sizeof(unsigned char)) * 8); 
#line 186
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 187
} 
#line 189
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char2> () 
#line 190
{ 
#line 191
int e = (((int)sizeof(signed char)) * 8); 
#line 193
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 194
} 
#line 196
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar2> () 
#line 197
{ 
#line 198
int e = (((int)sizeof(unsigned char)) * 8); 
#line 200
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 201
} 
#line 203
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< char4> () 
#line 204
{ 
#line 205
int e = (((int)sizeof(signed char)) * 8); 
#line 207
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 208
} 
#line 210
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uchar4> () 
#line 211
{ 
#line 212
int e = (((int)sizeof(unsigned char)) * 8); 
#line 214
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 215
} 
#line 217
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short> () 
#line 218
{ 
#line 219
int e = (((int)sizeof(short)) * 8); 
#line 221
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 222
} 
#line 224
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned short> () 
#line 225
{ 
#line 226
int e = (((int)sizeof(unsigned short)) * 8); 
#line 228
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 229
} 
#line 231
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short1> () 
#line 232
{ 
#line 233
int e = (((int)sizeof(short)) * 8); 
#line 235
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 236
} 
#line 238
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort1> () 
#line 239
{ 
#line 240
int e = (((int)sizeof(unsigned short)) * 8); 
#line 242
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 243
} 
#line 245
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short2> () 
#line 246
{ 
#line 247
int e = (((int)sizeof(short)) * 8); 
#line 249
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 250
} 
#line 252
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort2> () 
#line 253
{ 
#line 254
int e = (((int)sizeof(unsigned short)) * 8); 
#line 256
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 257
} 
#line 259
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< short4> () 
#line 260
{ 
#line 261
int e = (((int)sizeof(short)) * 8); 
#line 263
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 264
} 
#line 266
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ushort4> () 
#line 267
{ 
#line 268
int e = (((int)sizeof(unsigned short)) * 8); 
#line 270
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 271
} 
#line 273
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int> () 
#line 274
{ 
#line 275
int e = (((int)sizeof(int)) * 8); 
#line 277
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 278
} 
#line 280
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned> () 
#line 281
{ 
#line 282
int e = (((int)sizeof(unsigned)) * 8); 
#line 284
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 285
} 
#line 287
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int1> () 
#line 288
{ 
#line 289
int e = (((int)sizeof(int)) * 8); 
#line 291
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 292
} 
#line 294
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint1> () 
#line 295
{ 
#line 296
int e = (((int)sizeof(unsigned)) * 8); 
#line 298
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 299
} 
#line 301
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int2> () 
#line 302
{ 
#line 303
int e = (((int)sizeof(int)) * 8); 
#line 305
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 306
} 
#line 308
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint2> () 
#line 309
{ 
#line 310
int e = (((int)sizeof(unsigned)) * 8); 
#line 312
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 313
} 
#line 315
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< int4> () 
#line 316
{ 
#line 317
int e = (((int)sizeof(int)) * 8); 
#line 319
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 320
} 
#line 322
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< uint4> () 
#line 323
{ 
#line 324
int e = (((int)sizeof(unsigned)) * 8); 
#line 326
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 327
} 
#line 331
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long> () 
#line 332
{ 
#line 333
int e = (((int)sizeof(long)) * 8); 
#line 335
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 336
} 
#line 338
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< unsigned long> () 
#line 339
{ 
#line 340
int e = (((int)sizeof(unsigned long)) * 8); 
#line 342
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 343
} 
#line 345
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long1> () 
#line 346
{ 
#line 347
int e = (((int)sizeof(long)) * 8); 
#line 349
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindSigned); 
#line 350
} 
#line 352
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong1> () 
#line 353
{ 
#line 354
int e = (((int)sizeof(unsigned long)) * 8); 
#line 356
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindUnsigned); 
#line 357
} 
#line 359
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long2> () 
#line 360
{ 
#line 361
int e = (((int)sizeof(long)) * 8); 
#line 363
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindSigned); 
#line 364
} 
#line 366
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong2> () 
#line 367
{ 
#line 368
int e = (((int)sizeof(unsigned long)) * 8); 
#line 370
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindUnsigned); 
#line 371
} 
#line 373
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< long4> () 
#line 374
{ 
#line 375
int e = (((int)sizeof(long)) * 8); 
#line 377
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindSigned); 
#line 378
} 
#line 380
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< ulong4> () 
#line 381
{ 
#line 382
int e = (((int)sizeof(unsigned long)) * 8); 
#line 384
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindUnsigned); 
#line 385
} 
#line 389 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\channel_descriptor.h"
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float> () 
#line 390
{ 
#line 391
int e = (((int)sizeof(float)) * 8); 
#line 393
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 394
} 
#line 396
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float1> () 
#line 397
{ 
#line 398
int e = (((int)sizeof(float)) * 8); 
#line 400
return cudaCreateChannelDesc(e, 0, 0, 0, cudaChannelFormatKindFloat); 
#line 401
} 
#line 403
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float2> () 
#line 404
{ 
#line 405
int e = (((int)sizeof(float)) * 8); 
#line 407
return cudaCreateChannelDesc(e, e, 0, 0, cudaChannelFormatKindFloat); 
#line 408
} 
#line 410
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< float4> () 
#line 411
{ 
#line 412
int e = (((int)sizeof(float)) * 8); 
#line 414
return cudaCreateChannelDesc(e, e, e, e, cudaChannelFormatKindFloat); 
#line 415
} 
#line 417
static __inline cudaChannelFormatDesc cudaCreateChannelDescNV12() 
#line 418
{ 
#line 419
int e = (((int)sizeof(char)) * 8); 
#line 421
return cudaCreateChannelDesc(e, e, e, 0, cudaChannelFormatKindNV12); 
#line 422
} 
#line 424
template< cudaChannelFormatKind > __inline ::cudaChannelFormatDesc cudaCreateChannelDesc() 
#line 425
{ 
#line 426
return cudaCreateChannelDesc(0, 0, 0, 0, cudaChannelFormatKindNone); 
#line 427
} 
#line 430
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X1> () 
#line 431
{ 
#line 432
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSignedNormalized8X1); 
#line 433
} 
#line 435
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X2> () 
#line 436
{ 
#line 437
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindSignedNormalized8X2); 
#line 438
} 
#line 440
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized8X4> () 
#line 441
{ 
#line 442
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindSignedNormalized8X4); 
#line 443
} 
#line 446
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X1> () 
#line 447
{ 
#line 448
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsignedNormalized8X1); 
#line 449
} 
#line 451
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X2> () 
#line 452
{ 
#line 453
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindUnsignedNormalized8X2); 
#line 454
} 
#line 456
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized8X4> () 
#line 457
{ 
#line 458
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedNormalized8X4); 
#line 459
} 
#line 462
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X1> () 
#line 463
{ 
#line 464
return cudaCreateChannelDesc(16, 0, 0, 0, cudaChannelFormatKindSignedNormalized16X1); 
#line 465
} 
#line 467
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X2> () 
#line 468
{ 
#line 469
return cudaCreateChannelDesc(16, 16, 0, 0, cudaChannelFormatKindSignedNormalized16X2); 
#line 470
} 
#line 472
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedNormalized16X4> () 
#line 473
{ 
#line 474
return cudaCreateChannelDesc(16, 16, 16, 16, cudaChannelFormatKindSignedNormalized16X4); 
#line 475
} 
#line 478
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X1> () 
#line 479
{ 
#line 480
return cudaCreateChannelDesc(16, 0, 0, 0, cudaChannelFormatKindUnsignedNormalized16X1); 
#line 481
} 
#line 483
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X2> () 
#line 484
{ 
#line 485
return cudaCreateChannelDesc(16, 16, 0, 0, cudaChannelFormatKindUnsignedNormalized16X2); 
#line 486
} 
#line 488
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedNormalized16X4> () 
#line 489
{ 
#line 490
return cudaCreateChannelDesc(16, 16, 16, 16, cudaChannelFormatKindUnsignedNormalized16X4); 
#line 491
} 
#line 494
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindNV12> () 
#line 495
{ 
#line 496
return cudaCreateChannelDesc(8, 8, 8, 0, cudaChannelFormatKindNV12); 
#line 497
} 
#line 500
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed1> () 
#line 501
{ 
#line 502
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed1); 
#line 503
} 
#line 506
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed1SRGB> () 
#line 507
{ 
#line 508
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed1SRGB); 
#line 509
} 
#line 512
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed2> () 
#line 513
{ 
#line 514
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed2); 
#line 515
} 
#line 518
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed2SRGB> () 
#line 519
{ 
#line 520
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed2SRGB); 
#line 521
} 
#line 524
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed3> () 
#line 525
{ 
#line 526
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed3); 
#line 527
} 
#line 530
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed3SRGB> () 
#line 531
{ 
#line 532
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed3SRGB); 
#line 533
} 
#line 536
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed4> () 
#line 537
{ 
#line 538
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindUnsignedBlockCompressed4); 
#line 539
} 
#line 542
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed4> () 
#line 543
{ 
#line 544
return cudaCreateChannelDesc(8, 0, 0, 0, cudaChannelFormatKindSignedBlockCompressed4); 
#line 545
} 
#line 548
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed5> () 
#line 549
{ 
#line 550
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindUnsignedBlockCompressed5); 
#line 551
} 
#line 554
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed5> () 
#line 555
{ 
#line 556
return cudaCreateChannelDesc(8, 8, 0, 0, cudaChannelFormatKindSignedBlockCompressed5); 
#line 557
} 
#line 560
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed6H> () 
#line 561
{ 
#line 562
return cudaCreateChannelDesc(16, 16, 16, 0, cudaChannelFormatKindUnsignedBlockCompressed6H); 
#line 563
} 
#line 566
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindSignedBlockCompressed6H> () 
#line 567
{ 
#line 568
return cudaCreateChannelDesc(16, 16, 16, 0, cudaChannelFormatKindSignedBlockCompressed6H); 
#line 569
} 
#line 572
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed7> () 
#line 573
{ 
#line 574
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed7); 
#line 575
} 
#line 578
template<> __inline cudaChannelFormatDesc cudaCreateChannelDesc< cudaChannelFormatKindUnsignedBlockCompressed7SRGB> () 
#line 579
{ 
#line 580
return cudaCreateChannelDesc(8, 8, 8, 8, cudaChannelFormatKindUnsignedBlockCompressed7SRGB); 
#line 581
} 
#line 79 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\driver_functions.h"
static __inline cudaPitchedPtr make_cudaPitchedPtr(void *d, size_t p, size_t xsz, size_t ysz) 
#line 80
{ 
#line 81
cudaPitchedPtr s; 
#line 83
(s.ptr) = d; 
#line 84
(s.pitch) = p; 
#line 85
(s.xsize) = xsz; 
#line 86
(s.ysize) = ysz; 
#line 88
return s; 
#line 89
} 
#line 106
static __inline cudaPos make_cudaPos(size_t x, size_t y, size_t z) 
#line 107
{ 
#line 108
cudaPos p; 
#line 110
(p.x) = x; 
#line 111
(p.y) = y; 
#line 112
(p.z) = z; 
#line 114
return p; 
#line 115
} 
#line 132
static __inline cudaExtent make_cudaExtent(size_t w, size_t h, size_t d) 
#line 133
{ 
#line 134
cudaExtent e; 
#line 136
(e.width) = w; 
#line 137
(e.height) = h; 
#line 138
(e.depth) = d; 
#line 140
return e; 
#line 141
} 
#line 73 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_functions.h"
static __inline char1 make_char1(signed char x); 
#line 75
static __inline uchar1 make_uchar1(unsigned char x); 
#line 77
static __inline char2 make_char2(signed char x, signed char y); 
#line 79
static __inline uchar2 make_uchar2(unsigned char x, unsigned char y); 
#line 81
static __inline char3 make_char3(signed char x, signed char y, signed char z); 
#line 83
static __inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z); 
#line 85
static __inline char4 make_char4(signed char x, signed char y, signed char z, signed char w); 
#line 87
static __inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w); 
#line 89
static __inline short1 make_short1(short x); 
#line 91
static __inline ushort1 make_ushort1(unsigned short x); 
#line 93
static __inline short2 make_short2(short x, short y); 
#line 95
static __inline ushort2 make_ushort2(unsigned short x, unsigned short y); 
#line 97
static __inline short3 make_short3(short x, short y, short z); 
#line 99
static __inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z); 
#line 101
static __inline short4 make_short4(short x, short y, short z, short w); 
#line 103
static __inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w); 
#line 105
static __inline int1 make_int1(int x); 
#line 107
static __inline uint1 make_uint1(unsigned x); 
#line 109
static __inline int2 make_int2(int x, int y); 
#line 111
static __inline uint2 make_uint2(unsigned x, unsigned y); 
#line 113
static __inline int3 make_int3(int x, int y, int z); 
#line 115
static __inline uint3 make_uint3(unsigned x, unsigned y, unsigned z); 
#line 117
static __inline int4 make_int4(int x, int y, int z, int w); 
#line 119
static __inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w); 
#line 121
static __inline long1 make_long1(long x); 
#line 123
static __inline ulong1 make_ulong1(unsigned long x); 
#line 125
static __inline long2 make_long2(long x, long y); 
#line 127
static __inline ulong2 make_ulong2(unsigned long x, unsigned long y); 
#line 129
static __inline long3 make_long3(long x, long y, long z); 
#line 131
static __inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z); 
#line 133
static __inline long4 make_long4(long x, long y, long z, long w); 
#line 135
static __inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w); 
#line 137
static __inline float1 make_float1(float x); 
#line 139
static __inline float2 make_float2(float x, float y); 
#line 141
static __inline float3 make_float3(float x, float y, float z); 
#line 143
static __inline float4 make_float4(float x, float y, float z, float w); 
#line 145
static __inline longlong1 make_longlong1(__int64 x); 
#line 147
static __inline ulonglong1 make_ulonglong1(unsigned __int64 x); 
#line 149
static __inline longlong2 make_longlong2(__int64 x, __int64 y); 
#line 151
static __inline ulonglong2 make_ulonglong2(unsigned __int64 x, unsigned __int64 y); 
#line 153
static __inline longlong3 make_longlong3(__int64 x, __int64 y, __int64 z); 
#line 155
static __inline ulonglong3 make_ulonglong3(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z); 
#line 157
static __inline longlong4 make_longlong4(__int64 x, __int64 y, __int64 z, __int64 w); 
#line 159
static __inline ulonglong4 make_ulonglong4(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w); 
#line 161
static __inline double1 make_double1(double x); 
#line 163
static __inline double2 make_double2(double x, double y); 
#line 165
static __inline double3 make_double3(double x, double y, double z); 
#line 167
static __inline double4 make_double4(double x, double y, double z, double w); 
#line 73 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\vector_functions.hpp"
static __inline char1 make_char1(signed char x) 
#line 74
{ 
#line 75
char1 t; (t.x) = x; return t; 
#line 76
} 
#line 78
static __inline uchar1 make_uchar1(unsigned char x) 
#line 79
{ 
#line 80
uchar1 t; (t.x) = x; return t; 
#line 81
} 
#line 83
static __inline char2 make_char2(signed char x, signed char y) 
#line 84
{ 
#line 85
char2 t; (t.x) = x; (t.y) = y; return t; 
#line 86
} 
#line 88
static __inline uchar2 make_uchar2(unsigned char x, unsigned char y) 
#line 89
{ 
#line 90
uchar2 t; (t.x) = x; (t.y) = y; return t; 
#line 91
} 
#line 93
static __inline char3 make_char3(signed char x, signed char y, signed char z) 
#line 94
{ 
#line 95
char3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 96
} 
#line 98
static __inline uchar3 make_uchar3(unsigned char x, unsigned char y, unsigned char z) 
#line 99
{ 
#line 100
uchar3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 101
} 
#line 103
static __inline char4 make_char4(signed char x, signed char y, signed char z, signed char w) 
#line 104
{ 
#line 105
char4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 106
} 
#line 108
static __inline uchar4 make_uchar4(unsigned char x, unsigned char y, unsigned char z, unsigned char w) 
#line 109
{ 
#line 110
uchar4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 111
} 
#line 113
static __inline short1 make_short1(short x) 
#line 114
{ 
#line 115
short1 t; (t.x) = x; return t; 
#line 116
} 
#line 118
static __inline ushort1 make_ushort1(unsigned short x) 
#line 119
{ 
#line 120
ushort1 t; (t.x) = x; return t; 
#line 121
} 
#line 123
static __inline short2 make_short2(short x, short y) 
#line 124
{ 
#line 125
short2 t; (t.x) = x; (t.y) = y; return t; 
#line 126
} 
#line 128
static __inline ushort2 make_ushort2(unsigned short x, unsigned short y) 
#line 129
{ 
#line 130
ushort2 t; (t.x) = x; (t.y) = y; return t; 
#line 131
} 
#line 133
static __inline short3 make_short3(short x, short y, short z) 
#line 134
{ 
#line 135
short3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 136
} 
#line 138
static __inline ushort3 make_ushort3(unsigned short x, unsigned short y, unsigned short z) 
#line 139
{ 
#line 140
ushort3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 141
} 
#line 143
static __inline short4 make_short4(short x, short y, short z, short w) 
#line 144
{ 
#line 145
short4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 146
} 
#line 148
static __inline ushort4 make_ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) 
#line 149
{ 
#line 150
ushort4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 151
} 
#line 153
static __inline int1 make_int1(int x) 
#line 154
{ 
#line 155
int1 t; (t.x) = x; return t; 
#line 156
} 
#line 158
static __inline uint1 make_uint1(unsigned x) 
#line 159
{ 
#line 160
uint1 t; (t.x) = x; return t; 
#line 161
} 
#line 163
static __inline int2 make_int2(int x, int y) 
#line 164
{ 
#line 165
int2 t; (t.x) = x; (t.y) = y; return t; 
#line 166
} 
#line 168
static __inline uint2 make_uint2(unsigned x, unsigned y) 
#line 169
{ 
#line 170
uint2 t; (t.x) = x; (t.y) = y; return t; 
#line 171
} 
#line 173
static __inline int3 make_int3(int x, int y, int z) 
#line 174
{ 
#line 175
int3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 176
} 
#line 178
static __inline uint3 make_uint3(unsigned x, unsigned y, unsigned z) 
#line 179
{ 
#line 180
uint3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 181
} 
#line 183
static __inline int4 make_int4(int x, int y, int z, int w) 
#line 184
{ 
#line 185
int4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 186
} 
#line 188
static __inline uint4 make_uint4(unsigned x, unsigned y, unsigned z, unsigned w) 
#line 189
{ 
#line 190
uint4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 191
} 
#line 193
static __inline long1 make_long1(long x) 
#line 194
{ 
#line 195
long1 t; (t.x) = x; return t; 
#line 196
} 
#line 198
static __inline ulong1 make_ulong1(unsigned long x) 
#line 199
{ 
#line 200
ulong1 t; (t.x) = x; return t; 
#line 201
} 
#line 203
static __inline long2 make_long2(long x, long y) 
#line 204
{ 
#line 205
long2 t; (t.x) = x; (t.y) = y; return t; 
#line 206
} 
#line 208
static __inline ulong2 make_ulong2(unsigned long x, unsigned long y) 
#line 209
{ 
#line 210
ulong2 t; (t.x) = x; (t.y) = y; return t; 
#line 211
} 
#line 213
static __inline long3 make_long3(long x, long y, long z) 
#line 214
{ 
#line 215
long3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 216
} 
#line 218
static __inline ulong3 make_ulong3(unsigned long x, unsigned long y, unsigned long z) 
#line 219
{ 
#line 220
ulong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 221
} 
#line 223
static __inline long4 make_long4(long x, long y, long z, long w) 
#line 224
{ 
#line 225
long4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 226
} 
#line 228
static __inline ulong4 make_ulong4(unsigned long x, unsigned long y, unsigned long z, unsigned long w) 
#line 229
{ 
#line 230
ulong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 231
} 
#line 233
static __inline float1 make_float1(float x) 
#line 234
{ 
#line 235
float1 t; (t.x) = x; return t; 
#line 236
} 
#line 238
static __inline float2 make_float2(float x, float y) 
#line 239
{ 
#line 240
float2 t; (t.x) = x; (t.y) = y; return t; 
#line 241
} 
#line 243
static __inline float3 make_float3(float x, float y, float z) 
#line 244
{ 
#line 245
float3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 246
} 
#line 248
static __inline float4 make_float4(float x, float y, float z, float w) 
#line 249
{ 
#line 250
float4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 251
} 
#line 253
static __inline longlong1 make_longlong1(__int64 x) 
#line 254
{ 
#line 255
longlong1 t; (t.x) = x; return t; 
#line 256
} 
#line 258
static __inline ulonglong1 make_ulonglong1(unsigned __int64 x) 
#line 259
{ 
#line 260
ulonglong1 t; (t.x) = x; return t; 
#line 261
} 
#line 263
static __inline longlong2 make_longlong2(__int64 x, __int64 y) 
#line 264
{ 
#line 265
longlong2 t; (t.x) = x; (t.y) = y; return t; 
#line 266
} 
#line 268
static __inline ulonglong2 make_ulonglong2(unsigned __int64 x, unsigned __int64 y) 
#line 269
{ 
#line 270
ulonglong2 t; (t.x) = x; (t.y) = y; return t; 
#line 271
} 
#line 273
static __inline longlong3 make_longlong3(__int64 x, __int64 y, __int64 z) 
#line 274
{ 
#line 275
longlong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 276
} 
#line 278
static __inline ulonglong3 make_ulonglong3(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z) 
#line 279
{ 
#line 280
ulonglong3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 281
} 
#line 283
static __inline longlong4 make_longlong4(__int64 x, __int64 y, __int64 z, __int64 w) 
#line 284
{ 
#line 285
longlong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 286
} 
#line 288
static __inline ulonglong4 make_ulonglong4(unsigned __int64 x, unsigned __int64 y, unsigned __int64 z, unsigned __int64 w) 
#line 289
{ 
#line 290
ulonglong4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 291
} 
#line 293
static __inline double1 make_double1(double x) 
#line 294
{ 
#line 295
double1 t; (t.x) = x; return t; 
#line 296
} 
#line 298
static __inline double2 make_double2(double x, double y) 
#line 299
{ 
#line 300
double2 t; (t.x) = x; (t.y) = y; return t; 
#line 301
} 
#line 303
static __inline double3 make_double3(double x, double y, double z) 
#line 304
{ 
#line 305
double3 t; (t.x) = x; (t.y) = y; (t.z) = z; return t; 
#line 306
} 
#line 308
static __inline double4 make_double4(double x, double y, double z, double w) 
#line 309
{ 
#line 310
double4 t; (t.x) = x; (t.y) = y; (t.z) = z; (t.w) = w; return t; 
#line 311
} 
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\errno.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
int *__cdecl _errno(); 
#line 26
errno_t __cdecl _set_errno(int _Value); 
#line 27
errno_t __cdecl _get_errno(int * _Value); 
#line 29
unsigned long *__cdecl __doserrno(); 
#line 32
errno_t __cdecl _set_doserrno(unsigned long _Value); 
#line 33
errno_t __cdecl _get_doserrno(unsigned long * _Value); 
#line 134 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\errno.h"
}__pragma( pack ( pop )) 
#line 136
#pragma warning(pop)
#line 12 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_string.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 21
[[nodiscard]] const void *__cdecl 
#line 22
memchr(const void * _Buf, int _Val, size_t _MaxCount); 
#line 28
[[nodiscard]] int __cdecl 
#line 29
memcmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 43 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_string.h"
void *__cdecl memcpy(void * _Dst, const void * _Src, size_t _Size); 
#line 50
void *__cdecl memmove(void * _Dst, const void * _Src, size_t _Size); 
#line 63 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_string.h"
void *__cdecl memset(void * _Dst, int _Val, size_t _Size); 
#line 69
[[nodiscard]] const char *__cdecl 
#line 70
strchr(const char * _Str, int _Val); 
#line 75
[[nodiscard]] const char *__cdecl 
#line 76
strrchr(const char * _Str, int _Ch); 
#line 81
[[nodiscard]] const char *__cdecl 
#line 82
strstr(const char * _Str, const char * _SubStr); 
#line 87
[[nodiscard]] const __wchar_t *__cdecl 
#line 89
wcschr(const __wchar_t * _Str, __wchar_t _Ch); 
#line 94
[[nodiscard]] const __wchar_t *__cdecl 
#line 95
wcsrchr(const __wchar_t * _Str, __wchar_t _Ch); 
#line 100
[[nodiscard]] const __wchar_t *__cdecl 
#line 102
wcsstr(const __wchar_t * _Str, const __wchar_t * _SubStr); 
#line 109
}__pragma( pack ( pop )) 
#line 113 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_string.h"
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memcpy_s.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 39 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memcpy_s.h"
static __inline errno_t __cdecl memcpy_s(void *const 
#line 40
_Destination, const rsize_t 
#line 41
_DestinationSize, const void *const 
#line 42
_Source, const rsize_t 
#line 43
_SourceSize) 
#line 45
{ 
#line 46
if (_SourceSize == (0)) 
#line 47
{ 
#line 48
return 0; 
#line 49
}  
#line 51
{ int _Expr_val = !(!(_Destination != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 52
if ((_Source == (0)) || (_DestinationSize < _SourceSize)) 
#line 53
{ 
#line 54
memset(_Destination, 0, _DestinationSize); 
#line 56
{ int _Expr_val = !(!(_Source != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 57
{ int _Expr_val = !(!(_DestinationSize >= _SourceSize)); if (!_Expr_val) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; }  } ; 
#line 60
return 22; 
#line 61
}  
#line 62
memcpy(_Destination, _Source, _SourceSize); 
#line 63
return 0; 
#line 64
} 
#line 67
static __inline errno_t __cdecl memmove_s(void *const 
#line 68
_Destination, const rsize_t 
#line 69
_DestinationSize, const void *const 
#line 70
_Source, const rsize_t 
#line 71
_SourceSize) 
#line 73
{ 
#line 74
if (_SourceSize == (0)) 
#line 75
{ 
#line 76
return 0; 
#line 77
}  
#line 79
{ int _Expr_val = !(!(_Destination != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 80
{ int _Expr_val = !(!(_Source != (0))); if (!_Expr_val) { (*_errno()) = 22; _invalid_parameter_noinfo(); return 22; }  } ; 
#line 81
{ int _Expr_val = !(!(_DestinationSize >= _SourceSize)); if (!_Expr_val) { (*_errno()) = 34; _invalid_parameter_noinfo(); return 34; }  } ; 
#line 83
memmove(_Destination, _Source, _SourceSize); 
#line 84
return 0; 
#line 85
} 
#line 93 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memcpy_s.h"
}
#line 92
#pragma warning(pop)
__pragma( pack ( pop )) 
#line 17 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memory.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 23
__pragma( pack ( push, 8 )) extern "C" {
#line 28
int __cdecl _memicmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 35
int __cdecl _memicmp_l(const void * _Buf1, const void * _Buf2, size_t _Size, _locale_t _Locale); 
#line 83 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memory.h"
void *__cdecl memccpy(void * _Dst, const void * _Src, int _Val, size_t _Size); 
#line 91
int __cdecl memicmp(const void * _Buf1, const void * _Buf2, size_t _Size); 
#line 104 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memory.h"
extern "C++" inline void *__cdecl memchr(void *
#line 105
_Pv, int 
#line 106
_C, size_t 
#line 107
_N) 
#line 109
{ 
#line 110
const void *const _Pvc = _Pv; 
#line 111
return const_cast< void *>(memchr(_Pvc, _C, _N)); 
#line 112
} 
#line 118 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memory.h"
}__pragma( pack ( pop )) 
#line 122 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_memory.h"
#pragma warning(pop)
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 20
__pragma( pack ( push, 8 )) extern "C" {
#line 32
errno_t __cdecl wcscat_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source); 
#line 39
errno_t __cdecl wcscpy_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source); 
#line 46
errno_t __cdecl wcsncat_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source, rsize_t _MaxCount); 
#line 54
errno_t __cdecl wcsncpy_s(__wchar_t * _Destination, rsize_t _SizeInWords, const __wchar_t * _Source, rsize_t _MaxCount); 
#line 62
__wchar_t *__cdecl wcstok_s(__wchar_t * _String, const __wchar_t * _Delimiter, __wchar_t ** _Context); 
#line 83 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__declspec(allocator) __wchar_t *__cdecl _wcsdup(const __wchar_t * _String); 
#line 93 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcscat_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source ) throw ( ) { return wcscat_s ( _Destination, _Size, _Source ); }}
#line 100 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcscat(__wchar_t * _Destination, const __wchar_t * _Source); 
#line 108 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcscmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 113
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcscpy_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source ) throw ( ) { return wcscpy_s ( _Destination, _Size, _Source ); }}
#line 119 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcscpy(__wchar_t * _Destination, const __wchar_t * _Source); 
#line 126 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcscspn(const __wchar_t * _String, const __wchar_t * _Control); 
#line 132
size_t __cdecl wcslen(const __wchar_t * _String); 
#line 145 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcsnlen(const __wchar_t * _Source, size_t _MaxCount); 
#line 161 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
static __inline size_t __cdecl wcsnlen_s(const __wchar_t *
#line 162
_Source, size_t 
#line 163
_MaxCount) 
#line 165
{ 
#line 166
return (_Source == (0)) ? 0 : wcsnlen(_Source, _MaxCount); 
#line 167
} 
#line 171 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcsncat_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source, size_t _Count ) throw ( ) { return wcsncat_s ( _Destination, _Size, _Source, _Count ); }}
#line 178 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsncat(__wchar_t * _Destination, const __wchar_t * _Source, size_t _Count); 
#line 187 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcsncmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 193
extern "C++" {template < size_t _Size > inline errno_t __cdecl wcsncpy_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t const * _Source, size_t _Count ) throw ( ) { return wcsncpy_s ( _Destination, _Size, _Source, _Count ); }}
#line 200 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsncpy(__wchar_t * _Destination, const __wchar_t * _Source, size_t _Count); 
#line 209 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
const __wchar_t *__cdecl wcspbrk(const __wchar_t * _String, const __wchar_t * _Control); 
#line 215
size_t __cdecl wcsspn(const __wchar_t * _String, const __wchar_t * _Control); 
#line 221
__wchar_t *__cdecl wcstok(__wchar_t * _String, const __wchar_t * _Delimiter, __wchar_t ** _Context); 
#line 239 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
static __inline __wchar_t *__cdecl _wcstok(__wchar_t *const 
#line 240
_String, const __wchar_t *const 
#line 241
_Delimiter) 
#line 243
{ 
#line 244
return wcstok(_String, _Delimiter, 0); 
#line 245
} 
#line 253 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
extern "C++" 
#line 252
__declspec(deprecated("wcstok has been changed to conform with the ISO C standard, adding an extra context parameter. To use the legacy Microsoft wcsto" "k, define _CRT_NON_CONFORMING_WCSTOK.")) inline __wchar_t *__cdecl 
#line 253
wcstok(__wchar_t *
#line 254
_String, const __wchar_t *
#line 255
_Delimiter) throw() 
#line 257
{ 
#line 258
return wcstok(_String, _Delimiter, 0); 
#line 259
} 
#line 268 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcserror(int _ErrorNumber); 
#line 273
errno_t __cdecl _wcserror_s(__wchar_t * _Buffer, size_t _SizeInWords, int _ErrorNumber); 
#line 279
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], int _Error ) throw ( ) { return _wcserror_s ( _Buffer, _Size, _Error ); }}
#line 288 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl __wcserror(const __wchar_t * _String); 
#line 292
errno_t __cdecl __wcserror_s(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _ErrorMessage); 
#line 298
extern "C++" {template < size_t _Size > inline errno_t __cdecl __wcserror_s ( wchar_t ( & _Buffer ) [ _Size ], wchar_t const * _ErrorMessage ) throw ( ) { return __wcserror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 304 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
int __cdecl _wcsicmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 309
int __cdecl _wcsicmp_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 315
int __cdecl _wcsnicmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 321
int __cdecl _wcsnicmp_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 328
errno_t __cdecl _wcsnset_s(__wchar_t * _Destination, size_t _SizeInWords, __wchar_t _Value, size_t _MaxCount); 
#line 335
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsnset_s ( wchar_t ( & _Destination ) [ _Size ], wchar_t _Value, size_t _MaxCount ) throw ( ) { return _wcsnset_s ( _Destination, _Size, _Value, _MaxCount ); }}
#line 342 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsnset(__wchar_t * _String, __wchar_t _Value, size_t _MaxCount); 
#line 350 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsrev(__wchar_t * _String); 
#line 354
errno_t __cdecl _wcsset_s(__wchar_t * _Destination, size_t _SizeInWords, __wchar_t _Value); 
#line 360
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsset_s ( wchar_t ( & _String ) [ _Size ], wchar_t _Value ) throw ( ) { return _wcsset_s ( _String, _Size, _Value ); }}
#line 366 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsset(__wchar_t * _String, __wchar_t _Value); 
#line 373 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcslwr_s(__wchar_t * _String, size_t _SizeInWords); 
#line 378
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcslwr_s ( wchar_t ( & _String ) [ _Size ] ) throw ( ) { return _wcslwr_s ( _String, _Size ); }}
#line 383 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcslwr(__wchar_t * _String); 
#line 389 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcslwr_s_l(__wchar_t * _String, size_t _SizeInWords, _locale_t _Locale); 
#line 395
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcslwr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _wcslwr_s_l ( _String, _Size, _Locale ); }}
#line 401 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcslwr_l(__wchar_t * _String, _locale_t _Locale); 
#line 409 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcsupr_s(__wchar_t * _String, size_t _Size); 
#line 414
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsupr_s ( wchar_t ( & _String ) [ _Size ] ) throw ( ) { return _wcsupr_s ( _String, _Size ); }}
#line 419 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsupr(__wchar_t * _String); 
#line 425 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
errno_t __cdecl _wcsupr_s_l(__wchar_t * _String, size_t _Size, _locale_t _Locale); 
#line 431
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wcsupr_s_l ( wchar_t ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _wcsupr_s_l ( _String, _Size, _Locale ); }}
#line 437 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl _wcsupr_l(__wchar_t * _String, _locale_t _Locale); 
#line 446 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
size_t __cdecl wcsxfrm(__wchar_t * _Destination, const __wchar_t * _Source, size_t _MaxCount); 
#line 454
size_t __cdecl _wcsxfrm_l(__wchar_t * _Destination, const __wchar_t * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 462
int __cdecl wcscoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 468
int __cdecl _wcscoll_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 475
int __cdecl _wcsicoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 481
int __cdecl _wcsicoll_l(const __wchar_t * _String1, const __wchar_t * _String2, _locale_t _Locale); 
#line 488
int __cdecl _wcsncoll(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 495
int __cdecl _wcsncoll_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 503
int __cdecl _wcsnicoll(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 510
int __cdecl _wcsnicoll_l(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 525
extern "C++" {
#line 529
inline __wchar_t *__cdecl wcschr(__wchar_t *_String, __wchar_t _C) 
#line 530
{ 
#line 531
return const_cast< __wchar_t *>(wcschr(static_cast< const __wchar_t *>(_String), _C)); 
#line 532
} 
#line 535
inline __wchar_t *__cdecl wcspbrk(__wchar_t *_String, const __wchar_t *_Control) 
#line 536
{ 
#line 537
return const_cast< __wchar_t *>(wcspbrk(static_cast< const __wchar_t *>(_String), _Control)); 
#line 538
} 
#line 541
inline __wchar_t *__cdecl wcsrchr(__wchar_t *_String, __wchar_t _C) 
#line 542
{ 
#line 543
return const_cast< __wchar_t *>(wcsrchr(static_cast< const __wchar_t *>(_String), _C)); 
#line 544
} 
#line 548
inline __wchar_t *__cdecl wcsstr(__wchar_t *_String, const __wchar_t *_SubStr) 
#line 549
{ 
#line 550
return const_cast< __wchar_t *>(wcsstr(static_cast< const __wchar_t *>(_String), _SubStr)); 
#line 551
} 
#line 553
}
#line 570 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
__wchar_t *__cdecl wcsdup(const __wchar_t * _String); 
#line 582 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
int __cdecl wcsicmp(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 588
int __cdecl wcsnicmp(const __wchar_t * _String1, const __wchar_t * _String2, size_t _MaxCount); 
#line 596
__wchar_t *__cdecl wcsnset(__wchar_t * _String, __wchar_t _Value, size_t _MaxCount); 
#line 604
__wchar_t *__cdecl wcsrev(__wchar_t * _String); 
#line 610
__wchar_t *__cdecl wcsset(__wchar_t * _String, __wchar_t _Value); 
#line 617
__wchar_t *__cdecl wcslwr(__wchar_t * _String); 
#line 623
__wchar_t *__cdecl wcsupr(__wchar_t * _String); 
#line 628
int __cdecl wcsicoll(const __wchar_t * _String1, const __wchar_t * _String2); 
#line 637 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
}__pragma( pack ( pop )) 
#line 641 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wstring.h"
#pragma warning(pop)
#line 19 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 23
__pragma( pack ( push, 8 )) extern "C" {
#line 32
errno_t __cdecl strcpy_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source); 
#line 39
errno_t __cdecl strcat_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source); 
#line 46
errno_t __cdecl strerror_s(char * _Buffer, size_t _SizeInBytes, int _ErrorNumber); 
#line 52
errno_t __cdecl strncat_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source, rsize_t _MaxCount); 
#line 60
errno_t __cdecl strncpy_s(char * _Destination, rsize_t _SizeInBytes, const char * _Source, rsize_t _MaxCount); 
#line 68
char *__cdecl strtok_s(char * _String, const char * _Delimiter, char ** _Context); 
#line 76 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
void *__cdecl _memccpy(void * _Dst, const void * _Src, int _Val, size_t _MaxCount); 
#line 83
extern "C++" {template < size_t _Size > inline errno_t __cdecl strcat_s ( char ( & _Destination ) [ _Size ], char const * _Source ) throw ( ) { return strcat_s ( _Destination, _Size, _Source ); }}
#line 91 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strcat(char * _Destination, const char * _Source); 
#line 100 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
int __cdecl strcmp(const char * _Str1, const char * _Str2); 
#line 106
int __cdecl _strcmpi(const char * _String1, const char * _String2); 
#line 112
int __cdecl strcoll(const char * _String1, const char * _String2); 
#line 118
int __cdecl _strcoll_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 124
extern "C++" {template < size_t _Size > inline errno_t __cdecl strcpy_s ( char ( & _Destination ) [ _Size ], char const * _Source ) throw ( ) { return strcpy_s ( _Destination, _Size, _Source ); }}
#line 130 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strcpy(char * _Destination, const char * _Source); 
#line 137 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
size_t __cdecl strcspn(const char * _Str, const char * _Control); 
#line 148 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
__declspec(allocator) char *__cdecl _strdup(const char * _Source); 
#line 159 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strerror(const char * _ErrorMessage); 
#line 164
errno_t __cdecl _strerror_s(char * _Buffer, size_t _SizeInBytes, const char * _ErrorMessage); 
#line 170
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strerror_s ( char ( & _Buffer ) [ _Size ], char const * _ErrorMessage ) throw ( ) { return _strerror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 178 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strerror(int _ErrorMessage); 
#line 182
extern "C++" {template < size_t _Size > inline errno_t __cdecl strerror_s ( char ( & _Buffer ) [ _Size ], int _ErrorMessage ) throw ( ) { return strerror_s ( _Buffer, _Size, _ErrorMessage ); }}
#line 189 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
int __cdecl _stricmp(const char * _String1, const char * _String2); 
#line 195
int __cdecl _stricoll(const char * _String1, const char * _String2); 
#line 201
int __cdecl _stricoll_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 208
int __cdecl _stricmp_l(const char * _String1, const char * _String2, _locale_t _Locale); 
#line 215
size_t __cdecl strlen(const char * _Str); 
#line 220
errno_t __cdecl _strlwr_s(char * _String, size_t _Size); 
#line 225
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strlwr_s ( char ( & _String ) [ _Size ] ) throw ( ) { return _strlwr_s ( _String, _Size ); }}
#line 230 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strlwr(char * _String); 
#line 236 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
errno_t __cdecl _strlwr_s_l(char * _String, size_t _Size, _locale_t _Locale); 
#line 242
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strlwr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _strlwr_s_l ( _String, _Size, _Locale ); }}
#line 248 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strlwr_l(char * _String, _locale_t _Locale); 
#line 255 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl strncat_s ( char ( & _Destination ) [ _Size ], char const * _Source, size_t _Count ) throw ( ) { return strncat_s ( _Destination, _Size, _Source, _Count ); }}
#line 262 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strncat(char * _Destination, const char * _Source, size_t _Count); 
#line 271 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
int __cdecl strncmp(const char * _Str1, const char * _Str2, size_t _MaxCount); 
#line 278
int __cdecl _strnicmp(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 285
int __cdecl _strnicmp_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 293
int __cdecl _strnicoll(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 300
int __cdecl _strnicoll_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 308
int __cdecl _strncoll(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 315
int __cdecl _strncoll_l(const char * _String1, const char * _String2, size_t _MaxCount, _locale_t _Locale); 
#line 322
size_t __cdecl __strncnt(const char * _String, size_t _Count); 
#line 327
extern "C++" {template < size_t _Size > inline errno_t __cdecl strncpy_s ( char ( & _Destination ) [ _Size ], char const * _Source, size_t _Count ) throw ( ) { return strncpy_s ( _Destination, _Size, _Source, _Count ); }}
#line 334 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strncpy(char * _Destination, const char * _Source, size_t _Count); 
#line 351 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
size_t __cdecl strnlen(const char * _String, size_t _MaxCount); 
#line 367 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
static __inline size_t __cdecl strnlen_s(const char *
#line 368
_String, size_t 
#line 369
_MaxCount) 
#line 371
{ 
#line 372
return (_String == (0)) ? 0 : strnlen(_String, _MaxCount); 
#line 373
} 
#line 378 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
errno_t __cdecl _strnset_s(char * _String, size_t _SizeInBytes, int _Value, size_t _MaxCount); 
#line 385
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strnset_s ( char ( & _Destination ) [ _Size ], int _Value, size_t _Count ) throw ( ) { return _strnset_s ( _Destination, _Size, _Value, _Count ); }}
#line 392 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strnset(char * _Destination, int _Value, size_t _Count); 
#line 401 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
const char *__cdecl strpbrk(const char * _Str, const char * _Control); 
#line 406
char *__cdecl _strrev(char * _Str); 
#line 411
errno_t __cdecl _strset_s(char * _Destination, size_t _DestinationSize, int _Value); 
#line 417
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strset_s ( char ( & _Destination ) [ _Size ], int _Value ) throw ( ) { return _strset_s ( _Destination, _Size, _Value ); }}
#line 423 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strset(char * _Destination, int _Value); 
#line 430 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
size_t __cdecl strspn(const char * _Str, const char * _Control); 
#line 436
char *__cdecl strtok(char * _String, const char * _Delimiter); 
#line 442
errno_t __cdecl _strupr_s(char * _String, size_t _Size); 
#line 447
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strupr_s ( char ( & _String ) [ _Size ] ) throw ( ) { return _strupr_s ( _String, _Size ); }}
#line 452 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strupr(char * _String); 
#line 458 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
errno_t __cdecl _strupr_s_l(char * _String, size_t _Size, _locale_t _Locale); 
#line 464
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strupr_s_l ( char ( & _String ) [ _Size ], _locale_t _Locale ) throw ( ) { return _strupr_s_l ( _String, _Size, _Locale ); }}
#line 470 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl _strupr_l(char * _String, _locale_t _Locale); 
#line 479 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
size_t __cdecl strxfrm(char * _Destination, const char * _Source, size_t _MaxCount); 
#line 487
size_t __cdecl _strxfrm_l(char * _Destination, const char * _Source, size_t _MaxCount, _locale_t _Locale); 
#line 497
extern "C++" {
#line 500
inline char *__cdecl strchr(char *const _String, const int _Ch) 
#line 501
{ 
#line 502
return const_cast< char *>(strchr(static_cast< const char *>(_String), _Ch)); 
#line 503
} 
#line 506
inline char *__cdecl strpbrk(char *const _String, const char *const _Control) 
#line 507
{ 
#line 508
return const_cast< char *>(strpbrk(static_cast< const char *>(_String), _Control)); 
#line 509
} 
#line 512
inline char *__cdecl strrchr(char *const _String, const int _Ch) 
#line 513
{ 
#line 514
return const_cast< char *>(strrchr(static_cast< const char *>(_String), _Ch)); 
#line 515
} 
#line 518
inline char *__cdecl strstr(char *const _String, const char *const _SubString) 
#line 519
{ 
#line 520
return const_cast< char *>(strstr(static_cast< const char *>(_String), _SubString)); 
#line 521
} 
#line 522
}
#line 532 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
char *__cdecl strdup(const char * _String); 
#line 539
int __cdecl strcmpi(const char * _String1, const char * _String2); 
#line 545
int __cdecl stricmp(const char * _String1, const char * _String2); 
#line 551
char *__cdecl strlwr(char * _String); 
#line 556
int __cdecl strnicmp(const char * _String1, const char * _String2, size_t _MaxCount); 
#line 563
char *__cdecl strnset(char * _String, int _Value, size_t _MaxCount); 
#line 570
char *__cdecl strrev(char * _String); 
#line 575
char *__cdecl strset(char * _String, int _Value); 
#line 580
char *__cdecl strupr(char * _String); 
#line 588 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\string.h"
}__pragma( pack ( pop )) 
#line 590
#pragma warning(pop)
#line 13 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 17
__pragma( pack ( push, 8 )) extern "C" {
#line 26
struct tm { 
#line 28
int tm_sec; 
#line 29
int tm_min; 
#line 30
int tm_hour; 
#line 31
int tm_mday; 
#line 32
int tm_mon; 
#line 33
int tm_year; 
#line 34
int tm_wday; 
#line 35
int tm_yday; 
#line 36
int tm_isdst; 
#line 37
}; 
#line 48
__wchar_t *__cdecl _wasctime(const tm * _Tm); 
#line 54
errno_t __cdecl _wasctime_s(__wchar_t * _Buffer, size_t _SizeInWords, const tm * _Tm); 
#line 60
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wasctime_s ( wchar_t ( & _Buffer ) [ _Size ], struct tm const * _Time ) throw ( ) { return _wasctime_s ( _Buffer, _Size, _Time ); }}
#line 69 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
size_t __cdecl wcsftime(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _Format, const tm * _Tm); 
#line 78
size_t __cdecl _wcsftime_l(__wchar_t * _Buffer, size_t _SizeInWords, const __wchar_t * _Format, const tm * _Tm, _locale_t _Locale); 
#line 88
__wchar_t *__cdecl _wctime32(const __time32_t * _Time); 
#line 93
errno_t __cdecl _wctime32_s(__wchar_t * _Buffer, size_t _SizeInWords, const __time32_t * _Time); 
#line 99
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wctime32_s ( wchar_t ( & _Buffer ) [ _Size ], __time32_t const * _Time ) throw ( ) { return _wctime32_s ( _Buffer, _Size, _Time ); }}
#line 108 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wctime64(const __time64_t * _Time); 
#line 113
errno_t __cdecl _wctime64_s(__wchar_t * _Buffer, size_t _SizeInWords, const __time64_t * _Time); 
#line 118
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wctime64_s ( wchar_t ( & _Buffer ) [ _Size ], __time64_t const * _Time ) throw ( ) { return _wctime64_s ( _Buffer, _Size, _Time ); }}
#line 125 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
errno_t __cdecl _wstrdate_s(__wchar_t * _Buffer, size_t _SizeInWords); 
#line 130
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wstrdate_s ( wchar_t ( & _Buffer ) [ _Size ] ) throw ( ) { return _wstrdate_s ( _Buffer, _Size ); }}
#line 135 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wstrdate(__wchar_t * _Buffer); 
#line 141 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
errno_t __cdecl _wstrtime_s(__wchar_t * _Buffer, size_t _SizeInWords); 
#line 146
extern "C++" {template < size_t _Size > inline errno_t __cdecl _wstrtime_s ( wchar_t ( & _Buffer ) [ _Size ] ) throw ( ) { return _wstrtime_s ( _Buffer, _Size ); }}
#line 151 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
__wchar_t *__cdecl _wstrtime(__wchar_t * _Buffer); 
#line 186 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
static __inline __wchar_t *__cdecl _wctime(const time_t *const 
#line 187
_Time) 
#line 188
{ 
#line 189
return _wctime64(_Time); 
#line 190
} 
#line 193
static __inline errno_t __cdecl _wctime_s(__wchar_t *const 
#line 194
_Buffer, const size_t 
#line 195
_SizeInWords, const time_t *const 
#line 196
_Time) 
#line 198
{ 
#line 199
return _wctime64_s(_Buffer, _SizeInWords, _Time); 
#line 200
} 
#line 205 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_wtime.h"
}__pragma( pack ( pop )) 
#line 207
#pragma warning(pop)
#line 15 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 19
__pragma( pack ( push, 8 )) extern "C" {
#line 28
typedef long clock_t; 
#line 30
struct _timespec32 { 
#line 32
__time32_t tv_sec; 
#line 33
long tv_nsec; 
#line 34
}; 
#line 36
struct _timespec64 { 
#line 38
__time64_t tv_sec; 
#line 39
long tv_nsec; 
#line 40
}; 
#line 43
struct timespec { 
#line 45
time_t tv_sec; 
#line 46
long tv_nsec; 
#line 47
}; 
#line 66 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
int *__cdecl __daylight(); 
#line 72
long *__cdecl __dstbias(); 
#line 78
long *__cdecl __timezone(); 
#line 84
char **__cdecl __tzname(); 
#line 89
errno_t __cdecl _get_daylight(int * _Daylight); 
#line 94
errno_t __cdecl _get_dstbias(long * _DaylightSavingsBias); 
#line 99
errno_t __cdecl _get_timezone(long * _TimeZone); 
#line 104
errno_t __cdecl _get_tzname(size_t * _ReturnValue, char * _Buffer, size_t _SizeInBytes, int _Index); 
#line 121
char *__cdecl asctime(const tm * _Tm); 
#line 128
errno_t __cdecl asctime_s(char * _Buffer, size_t _SizeInBytes, const tm * _Tm); 
#line 135 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
extern "C++" {template < size_t _Size > inline errno_t __cdecl asctime_s ( char ( & _Buffer ) [ _Size ], struct tm const * _Time ) throw ( ) { return asctime_s ( _Buffer, _Size, _Time ); }}
#line 142 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
clock_t __cdecl clock(); 
#line 147
char *__cdecl _ctime32(const __time32_t * _Time); 
#line 152
errno_t __cdecl _ctime32_s(char * _Buffer, size_t _SizeInBytes, const __time32_t * _Time); 
#line 158
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ctime32_s ( char ( & _Buffer ) [ _Size ], __time32_t const * _Time ) throw ( ) { return _ctime32_s ( _Buffer, _Size, _Time ); }}
#line 167 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
char *__cdecl _ctime64(const __time64_t * _Time); 
#line 172
errno_t __cdecl _ctime64_s(char * _Buffer, size_t _SizeInBytes, const __time64_t * _Time); 
#line 178
extern "C++" {template < size_t _Size > inline errno_t __cdecl _ctime64_s ( char ( & _Buffer ) [ _Size ], __time64_t const * _Time ) throw ( ) { return _ctime64_s ( _Buffer, _Size, _Time ); }}
#line 185 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
double __cdecl _difftime32(__time32_t _Time1, __time32_t _Time2); 
#line 191
double __cdecl _difftime64(__time64_t _Time1, __time64_t _Time2); 
#line 198
tm *__cdecl _gmtime32(const __time32_t * _Time); 
#line 203
errno_t __cdecl _gmtime32_s(tm * _Tm, const __time32_t * _Time); 
#line 210
tm *__cdecl _gmtime64(const __time64_t * _Time); 
#line 215
errno_t __cdecl _gmtime64_s(tm * _Tm, const __time64_t * _Time); 
#line 222
tm *__cdecl _localtime32(const __time32_t * _Time); 
#line 227
errno_t __cdecl _localtime32_s(tm * _Tm, const __time32_t * _Time); 
#line 234
tm *__cdecl _localtime64(const __time64_t * _Time); 
#line 239
errno_t __cdecl _localtime64_s(tm * _Tm, const __time64_t * _Time); 
#line 245
__time32_t __cdecl _mkgmtime32(tm * _Tm); 
#line 250
__time64_t __cdecl _mkgmtime64(tm * _Tm); 
#line 255
__time32_t __cdecl _mktime32(tm * _Tm); 
#line 260
__time64_t __cdecl _mktime64(tm * _Tm); 
#line 266
size_t __cdecl strftime(char * _Buffer, size_t _SizeInBytes, const char * _Format, const tm * _Tm); 
#line 275
size_t __cdecl _strftime_l(char * _Buffer, size_t _MaxSize, const char * _Format, const tm * _Tm, _locale_t _Locale); 
#line 284
errno_t __cdecl _strdate_s(char * _Buffer, size_t _SizeInBytes); 
#line 289
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strdate_s ( char ( & _Buffer ) [ _Size ] ) throw ( ) { return _strdate_s ( _Buffer, _Size ); }}
#line 294 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
char *__cdecl _strdate(char * _Buffer); 
#line 300 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
errno_t __cdecl _strtime_s(char * _Buffer, size_t _SizeInBytes); 
#line 305
extern "C++" {template < size_t _Size > inline errno_t __cdecl _strtime_s ( char ( & _Buffer ) [ _Size ] ) throw ( ) { return _strtime_s ( _Buffer, _Size ); }}
#line 310 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
char *__cdecl _strtime(char * _Buffer); 
#line 315 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
__time32_t __cdecl _time32(__time32_t * _Time); 
#line 319
__time64_t __cdecl _time64(__time64_t * _Time); 
#line 325
int __cdecl _timespec32_get(_timespec32 * _Ts, int _Base); 
#line 332
int __cdecl _timespec64_get(_timespec64 * _Ts, int _Base); 
#line 346
void __cdecl _tzset(); 
#line 349
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using GetLocalTime in" "stead. See online help for details.")) unsigned __cdecl 
#line 350
_getsystime(tm * _Tm); 
#line 354
__declspec(deprecated("This function or variable has been superceded by newer library or operating system functionality. Consider using SetLocalTime in" "stead. See online help for details.")) unsigned __cdecl 
#line 355
_setsystime(tm * _Tm, unsigned _Milliseconds); 
#line 471 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
static __inline char *__cdecl ctime(const time_t *const 
#line 472
_Time) 
#line 474
{ 
#line 475
return _ctime64(_Time); 
#line 476
} 
#line 479
static __inline double __cdecl difftime(const time_t 
#line 480
_Time1, const time_t 
#line 481
_Time2) 
#line 483
{ 
#line 484
return _difftime64(_Time1, _Time2); 
#line 485
} 
#line 488
static __inline tm *__cdecl gmtime(const time_t *const 
#line 489
_Time) 
#line 490
{ 
#line 491
return _gmtime64(_Time); 
#line 492
} 
#line 495
static __inline tm *__cdecl localtime(const time_t *const 
#line 496
_Time) 
#line 498
{ 
#line 499
return _localtime64(_Time); 
#line 500
} 
#line 503
static __inline time_t __cdecl _mkgmtime(tm *const 
#line 504
_Tm) 
#line 506
{ 
#line 507
return _mkgmtime64(_Tm); 
#line 508
} 
#line 511
static __inline time_t __cdecl mktime(tm *const 
#line 512
_Tm) 
#line 514
{ 
#line 515
return _mktime64(_Tm); 
#line 516
} 
#line 518
static __inline time_t __cdecl time(time_t *const 
#line 519
_Time) 
#line 521
{ 
#line 522
return _time64(_Time); 
#line 523
} 
#line 526
static __inline int __cdecl timespec_get(timespec *const 
#line 527
_Ts, const int 
#line 528
_Base) 
#line 530
{ 
#line 531
return _timespec64_get((_timespec64 *)_Ts, _Base); 
#line 532
} 
#line 536
static __inline errno_t __cdecl ctime_s(char *const 
#line 537
_Buffer, const size_t 
#line 538
_SizeInBytes, const time_t *const 
#line 539
_Time) 
#line 541
{ 
#line 542
return _ctime64_s(_Buffer, _SizeInBytes, _Time); 
#line 543
} 
#line 546
static __inline errno_t __cdecl gmtime_s(tm *const 
#line 547
_Tm, const time_t *const 
#line 548
_Time) 
#line 550
{ 
#line 551
return _gmtime64_s(_Tm, _Time); 
#line 552
} 
#line 555
static __inline errno_t __cdecl localtime_s(tm *const 
#line 556
_Tm, const time_t *const 
#line 557
_Time) 
#line 559
{ 
#line 560
return _localtime64_s(_Tm, _Time); 
#line 561
} 
#line 580 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
void __cdecl tzset(); 
#line 587 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\time.h"
}__pragma( pack ( pop )) 
#line 589
#pragma warning(pop)
#line 88 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/common_functions.h"
extern "C" {
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/common_functions.h"
extern clock_t __cdecl clock(); 
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/common_functions.h"
extern void *__cdecl memset(void *, int, size_t); 
#line 97
extern void *__cdecl memcpy(void *, const void *, size_t); 
#line 99
}
#line 121 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern "C" {
#line 219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __cdecl abs(int a); 
#line 227
extern long __cdecl labs(long a); 
#line 235
extern __int64 llabs(__int64 a); 
#line 285 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl fabs(double x); 
#line 328
extern __inline float fabsf(float x); 
#line 338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline int min(const int a, const int b); 
#line 345
extern inline unsigned umin(const unsigned a, const unsigned b); 
#line 352
extern inline __int64 llmin(const __int64 a, const __int64 b); 
#line 359
extern inline unsigned __int64 ullmin(const unsigned __int64 a, const unsigned __int64 b); 
#line 382 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl fminf(float x, float y); 
#line 402 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl fmin(double x, double y); 
#line 413 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline int max(const int a, const int b); 
#line 421
extern inline unsigned umax(const unsigned a, const unsigned b); 
#line 428
extern inline __int64 llmax(const __int64 a, const __int64 b); 
#line 435
extern inline unsigned __int64 ullmax(const unsigned __int64 a, const unsigned __int64 b); 
#line 458 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl fmaxf(float x, float y); 
#line 478 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl fmax(double, double); 
#line 520 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl sin(double x); 
#line 553
extern double __cdecl cos(double x); 
#line 572 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern void sincos(double x, double * sptr, double * cptr); 
#line 588
extern void sincosf(float x, float * sptr, float * cptr); 
#line 633 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl tan(double x); 
#line 702
extern double __cdecl sqrt(double x); 
#line 774 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double rsqrt(double x); 
#line 844
extern float rsqrtf(float x); 
#line 902 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl log2(double x); 
#line 967 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl exp2(double x); 
#line 1032 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl exp2f(float x); 
#line 1097 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double exp10(double x); 
#line 1160
extern float exp10f(float x); 
#line 1255 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl expm1(double x); 
#line 1347 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl expm1f(float x); 
#line 1403 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl log2f(float x); 
#line 1455 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl log10(double x); 
#line 1525
extern double __cdecl log(double x); 
#line 1623 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl log1p(double x); 
#line 1722 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl log1pf(float x); 
#line 1784 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl floor(double x); 
#line 1863
extern double __cdecl exp(double x); 
#line 1904
extern double __cdecl cosh(double x); 
#line 1954
extern double __cdecl sinh(double x); 
#line 2004
extern double __cdecl tanh(double x); 
#line 2061 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl acosh(double x); 
#line 2119 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl acoshf(float x); 
#line 2172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl asinh(double x); 
#line 2225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl asinhf(float x); 
#line 2279 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl atanh(double x); 
#line 2333 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl atanhf(float x); 
#line 2380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl ldexp(double x, int exp); 
#line 2426
extern __inline float ldexpf(float x, int exp); 
#line 2480 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl logb(double x); 
#line 2535 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl logbf(float x); 
#line 2575 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __cdecl ilogb(double x); 
#line 2615 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __cdecl ilogbf(float x); 
#line 2691 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl scalbn(double x, int n); 
#line 2767 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl scalbnf(float x, int n); 
#line 2843 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl scalbln(double x, long n); 
#line 2919 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl scalblnf(float x, long n); 
#line 2994 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl frexp(double x, int * nptr); 
#line 3068
extern __inline float frexpf(float x, int * nptr); 
#line 3122 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl round(double x); 
#line 3177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl roundf(float x); 
#line 3195 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern long __cdecl lround(double x); 
#line 3213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern long __cdecl lroundf(float x); 
#line 3231 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llround(double x); 
#line 3249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llroundf(float x); 
#line 3377 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl rintf(float x); 
#line 3394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern long __cdecl lrint(double x); 
#line 3411 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern long __cdecl lrintf(float x); 
#line 3428 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llrint(double x); 
#line 3445 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern __int64 __cdecl llrintf(float x); 
#line 3498 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl nearbyint(double x); 
#line 3551 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl nearbyintf(float x); 
#line 3611 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl ceil(double x); 
#line 3663 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl trunc(double x); 
#line 3716 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl truncf(float x); 
#line 3742 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl fdim(double x, double y); 
#line 3768 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl fdimf(float x, float y); 
#line 4066 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl atan2(double y, double x); 
#line 4137
extern double __cdecl atan(double x); 
#line 4160
extern double __cdecl acos(double x); 
#line 4211
extern double __cdecl asin(double x); 
#line 4276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl hypot(double x, double y); 
#line 4400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline float __cdecl hypotf(float x, float y); 
#line 5190 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl cbrt(double x); 
#line 5276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl cbrtf(float x); 
#line 5329 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double rcbrt(double x); 
#line 5379
extern float rcbrtf(float x); 
#line 5439
extern double sinpi(double x); 
#line 5499
extern float sinpif(float x); 
#line 5551
extern double cospi(double x); 
#line 5603
extern float cospif(float x); 
#line 5633
extern void sincospi(double x, double * sptr, double * cptr); 
#line 5663
extern void sincospif(float x, float * sptr, float * cptr); 
#line 5996 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl pow(double x, double y); 
#line 6052
extern double __cdecl modf(double x, double * iptr); 
#line 6111
extern double __cdecl fmod(double x, double y); 
#line 6209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl remainder(double x, double y); 
#line 6308 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl remainderf(float x, float y); 
#line 6380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl remquo(double x, double y, int * quo); 
#line 6452 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl remquof(float x, float y, int * quo); 
#line 6491 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl j0(double x); 
#line 6533 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float j0f(float x); 
#line 6602 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl j1(double x); 
#line 6671 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float j1f(float x); 
#line 6714 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl jn(int n, double x); 
#line 6757 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float jnf(int n, float x); 
#line 6818 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl y0(double x); 
#line 6879 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float y0f(float x); 
#line 6940 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl y1(double x); 
#line 7001 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float y1f(float x); 
#line 7064 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl yn(int n, double x); 
#line 7127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float ynf(int n, float x); 
#line 7318 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl erf(double x); 
#line 7400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl erff(float x); 
#line 7470 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double erfinv(double x); 
#line 7535
extern float erfinvf(float x); 
#line 7576 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl erfc(double x); 
#line 7614 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl erfcf(float x); 
#line 7731 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl lgamma(double x); 
#line 7791 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double erfcinv(double x); 
#line 7846
extern float erfcinvf(float x); 
#line 7914
extern double normcdfinv(double x); 
#line 7982
extern float normcdfinvf(float x); 
#line 8025
extern double normcdf(double x); 
#line 8068
extern float normcdff(float x); 
#line 8132
extern double erfcx(double x); 
#line 8196
extern float erfcxf(float x); 
#line 8317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl lgammaf(float x); 
#line 8415 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl tgamma(double x); 
#line 8513 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl tgammaf(float x); 
#line 8526 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl copysign(double x, double y); 
#line 8539 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl copysignf(float x, float y); 
#line 8558 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl nextafter(double x, double y); 
#line 8577 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl nextafterf(float x, float y); 
#line 8593 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl nan(const char * tagp); 
#line 8609 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl nanf(const char * tagp); 
#line 8614 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __isinff(float); 
#line 8615
extern int __isnanf(float); 
#line 8625 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __finite(double); 
#line 8626
extern int __finitef(float); 
#line 8627
extern int __signbit(double); 
#line 8628
extern int __isnan(double); 
#line 8629
extern int __isinf(double); 
#line 8632 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __signbitf(float); 
#line 8793 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern double __cdecl fma(double x, double y, double z); 
#line 8951 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl fmaf(float x, float y, float z); 
#line 8960 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __signbitl(long double); 
#line 8966 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern int __finitel(long double); 
#line 8967
extern int __isinfl(long double); 
#line 8968
extern int __isnanl(long double); 
#line 8972 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern float __cdecl acosf(float); 
#line 8973
extern float __cdecl asinf(float); 
#line 8974
extern float __cdecl atanf(float); 
#line 8975
extern float __cdecl atan2f(float, float); 
#line 8976
extern float __cdecl cosf(float); 
#line 8977
extern float __cdecl sinf(float); 
#line 8978
extern float __cdecl tanf(float); 
#line 8979
extern float __cdecl coshf(float); 
#line 8980
extern float __cdecl sinhf(float); 
#line 8981
extern float __cdecl tanhf(float); 
#line 8982
extern float __cdecl expf(float); 
#line 8983
extern float __cdecl logf(float); 
#line 8984
extern float __cdecl log10f(float); 
#line 8985
extern float __cdecl modff(float, float *); 
#line 8986
extern float __cdecl powf(float, float); 
#line 8987
extern float __cdecl sqrtf(float); 
#line 8988
extern float __cdecl ceilf(float); 
#line 8989
extern float __cdecl floorf(float); 
#line 8990
extern float __cdecl fmodf(float, float); 
#line 10544 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
}
#line 14 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 18
__pragma( pack ( push, 8 )) extern "C" {
#line 23
struct _exception { 
#line 25
int type; 
#line 26
char *name; 
#line 27
double arg1; 
#line 28
double arg2; 
#line 29
double retval; 
#line 30
}; 
#line 37
struct _complex { 
#line 39
double x, y; 
#line 40
}; 
#line 59 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
typedef float float_t; 
#line 60
typedef double double_t; 
#line 78 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
extern const double _HUGE; 
#line 175 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
void __cdecl _fperrraise(int _Except); 
#line 177
short __cdecl _dclass(double _X); 
#line 178
short __cdecl _ldclass(long double _X); 
#line 179
short __cdecl _fdclass(float _X); 
#line 181
int __cdecl _dsign(double _X); 
#line 182
int __cdecl _ldsign(long double _X); 
#line 183
int __cdecl _fdsign(float _X); 
#line 185
int __cdecl _dpcomp(double _X, double _Y); 
#line 186
int __cdecl _ldpcomp(long double _X, long double _Y); 
#line 187
int __cdecl _fdpcomp(float _X, float _Y); 
#line 189
short __cdecl _dtest(double * _Px); 
#line 190
short __cdecl _ldtest(long double * _Px); 
#line 191
short __cdecl _fdtest(float * _Px); 
#line 193
short __cdecl _d_int(double * _Px, short _Xexp); 
#line 194
short __cdecl _ld_int(long double * _Px, short _Xexp); 
#line 195
short __cdecl _fd_int(float * _Px, short _Xexp); 
#line 197
short __cdecl _dscale(double * _Px, long _Lexp); 
#line 198
short __cdecl _ldscale(long double * _Px, long _Lexp); 
#line 199
short __cdecl _fdscale(float * _Px, long _Lexp); 
#line 201
short __cdecl _dunscale(short * _Pex, double * _Px); 
#line 202
short __cdecl _ldunscale(short * _Pex, long double * _Px); 
#line 203
short __cdecl _fdunscale(short * _Pex, float * _Px); 
#line 205
short __cdecl _dexp(double * _Px, double _Y, long _Eoff); 
#line 206
short __cdecl _ldexp(long double * _Px, long double _Y, long _Eoff); 
#line 207
short __cdecl _fdexp(float * _Px, float _Y, long _Eoff); 
#line 209
short __cdecl _dnorm(unsigned short * _Ps); 
#line 210
short __cdecl _fdnorm(unsigned short * _Ps); 
#line 212
double __cdecl _dpoly(double _X, const double * _Tab, int _N); 
#line 213
long double __cdecl _ldpoly(long double _X, const long double * _Tab, int _N); 
#line 214
float __cdecl _fdpoly(float _X, const float * _Tab, int _N); 
#line 216
double __cdecl _dlog(double _X, int _Baseflag); 
#line 217
long double __cdecl _ldlog(long double _X, int _Baseflag); 
#line 218
float __cdecl _fdlog(float _X, int _Baseflag); 
#line 220
double __cdecl _dsin(double _X, unsigned _Qoff); 
#line 221
long double __cdecl _ldsin(long double _X, unsigned _Qoff); 
#line 222
float __cdecl _fdsin(float _X, unsigned _Qoff); 
#line 229
typedef 
#line 226
union { 
#line 227
unsigned short _Sh[4]; 
#line 228
double _Val; 
#line 229
} _double_val; 
#line 236
typedef 
#line 233
union { 
#line 234
unsigned short _Sh[2]; 
#line 235
float _Val; 
#line 236
} _float_val; 
#line 243
typedef 
#line 240
union { 
#line 241
unsigned short _Sh[4]; 
#line 242
long double _Val; 
#line 243
} _ldouble_val; 
#line 251
typedef 
#line 246
union { 
#line 247
unsigned short _Word[4]; 
#line 248
float _Float; 
#line 249
double _Double; 
#line 250
long double _Long_double; 
#line 251
} _float_const; 
#line 253
extern const _float_const _Denorm_C, _Inf_C, _Nan_C, _Snan_C, _Hugeval_C; 
#line 254
extern const _float_const _FDenorm_C, _FInf_C, _FNan_C, _FSnan_C; 
#line 255
extern const _float_const _LDenorm_C, _LInf_C, _LNan_C, _LSnan_C; 
#line 257
extern const _float_const _Eps_C, _Rteps_C; 
#line 258
extern const _float_const _FEps_C, _FRteps_C; 
#line 259
extern const _float_const _LEps_C, _LRteps_C; 
#line 261
extern const double _Zero_C, _Xbig_C; 
#line 262
extern const float _FZero_C, _FXbig_C; 
#line 263
extern const long double _LZero_C, _LXbig_C; 
#line 292
extern "C++" {
#line 294
inline int fpclassify(float _X) throw() 
#line 295
{ 
#line 296
return _fdtest(&_X); 
#line 297
} 
#line 299
inline int fpclassify(double _X) throw() 
#line 300
{ 
#line 301
return _dtest(&_X); 
#line 302
} 
#line 304
inline int fpclassify(long double _X) throw() 
#line 305
{ 
#line 306
return _ldtest(&_X); 
#line 307
} 
#line 309
inline bool signbit(float _X) throw() 
#line 310
{ 
#line 311
return _fdsign(_X) != 0; 
#line 312
} 
#line 314
inline bool signbit(double _X) throw() 
#line 315
{ 
#line 316
return _dsign(_X) != 0; 
#line 317
} 
#line 319
inline bool signbit(long double _X) throw() 
#line 320
{ 
#line 321
return _ldsign(_X) != 0; 
#line 322
} 
#line 324
inline int _fpcomp(float _X, float _Y) throw() 
#line 325
{ 
#line 326
return _fdpcomp(_X, _Y); 
#line 327
} 
#line 329
inline int _fpcomp(double _X, double _Y) throw() 
#line 330
{ 
#line 331
return _dpcomp(_X, _Y); 
#line 332
} 
#line 334
inline int _fpcomp(long double _X, long double _Y) throw() 
#line 335
{ 
#line 336
return _ldpcomp(_X, _Y); 
#line 337
} 
#line 339
template< class _Trc, class _Tre> struct _Combined_type { 
#line 341
typedef float _Type; 
#line 342
}; 
#line 344
template<> struct _Combined_type< float, double>  { 
#line 346
typedef double _Type; 
#line 347
}; 
#line 349
template<> struct _Combined_type< float, long double>  { 
#line 351
typedef long double _Type; 
#line 352
}; 
#line 354
template< class _Ty, class _T2> struct _Real_widened { 
#line 356
typedef long double _Type; 
#line 357
}; 
#line 359
template<> struct _Real_widened< float, float>  { 
#line 361
typedef float _Type; 
#line 362
}; 
#line 364
template<> struct _Real_widened< float, double>  { 
#line 366
typedef double _Type; 
#line 367
}; 
#line 369
template<> struct _Real_widened< double, float>  { 
#line 371
typedef double _Type; 
#line 372
}; 
#line 374
template<> struct _Real_widened< double, double>  { 
#line 376
typedef double _Type; 
#line 377
}; 
#line 379
template< class _Ty> struct _Real_type { 
#line 381
typedef double _Type; 
#line 382
}; 
#line 384
template<> struct _Real_type< float>  { 
#line 386
typedef float _Type; 
#line 387
}; 
#line 389
template<> struct _Real_type< long double>  { 
#line 391
typedef long double _Type; 
#line 392
}; 
#line 394
template < class _T1, class _T2 >
      inline int _fpcomp ( _T1 _X, _T2 _Y ) throw ( )
    {
        typedef typename _Combined_type < float,
            typename _Real_widened <
            typename _Real_type < _T1 > :: _Type,
            typename _Real_type < _T2 > :: _Type > :: _Type > :: _Type _Tw;
        return _fpcomp ( ( _Tw ) _X, ( _Tw ) _Y );
    }
#line 404
template < class _Ty >
      inline bool isfinite ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) <= 0;
    }
#line 410
template < class _Ty >
      inline bool isinf ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == 1;
    }
#line 416
template < class _Ty >
      inline bool isnan ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == 2;
    }
#line 422
template < class _Ty >
      inline bool isnormal ( _Ty _X ) throw ( )
    {
        return fpclassify ( _X ) == ( - 1 );
    }
#line 428
template < class _Ty1, class _Ty2 >
      inline bool isgreater ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & 4 ) != 0;
    }
#line 434
template < class _Ty1, class _Ty2 >
      inline bool isgreaterequal ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 2 | 4 ) ) != 0;
    }
#line 440
template < class _Ty1, class _Ty2 >
      inline bool isless ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & 1 ) != 0;
    }
#line 446
template < class _Ty1, class _Ty2 >
      inline bool islessequal ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 1 | 2 ) ) != 0;
    }
#line 452
template < class _Ty1, class _Ty2 >
      inline bool islessgreater ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return ( _fpcomp ( _X, _Y ) & ( 1 | 4 ) ) != 0;
    }
#line 458
template < class _Ty1, class _Ty2 >
      inline bool isunordered ( _Ty1 _X, _Ty2 _Y ) throw ( )
    {
        return _fpcomp ( _X, _Y ) == 0;
    }
#line 463
}
#line 470 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
int __cdecl abs(int _X); 
#line 471
long __cdecl labs(long _X); 
#line 472
__int64 __cdecl llabs(__int64 _X); 
#line 474
double __cdecl acos(double _X); 
#line 475
double __cdecl asin(double _X); 
#line 476
double __cdecl atan(double _X); 
#line 477
double __cdecl atan2(double _Y, double _X); 
#line 479
double __cdecl cos(double _X); 
#line 480
double __cdecl cosh(double _X); 
#line 481
double __cdecl exp(double _X); 
#line 482
double __cdecl fabs(double _X); 
#line 483
double __cdecl fmod(double _X, double _Y); 
#line 484
double __cdecl log(double _X); 
#line 485
double __cdecl log10(double _X); 
#line 486
double __cdecl pow(double _X, double _Y); 
#line 487
double __cdecl sin(double _X); 
#line 488
double __cdecl sinh(double _X); 
#line 489
double __cdecl sqrt(double _X); 
#line 490
double __cdecl tan(double _X); 
#line 491
double __cdecl tanh(double _X); 
#line 493
double __cdecl acosh(double _X); 
#line 494
double __cdecl asinh(double _X); 
#line 495
double __cdecl atanh(double _X); 
#line 496
double __cdecl atof(const char * _String); 
#line 497
double __cdecl _atof_l(const char * _String, _locale_t _Locale); 
#line 498
double __cdecl _cabs(_complex _Complex_value); 
#line 499
double __cdecl cbrt(double _X); 
#line 500
double __cdecl ceil(double _X); 
#line 501
double __cdecl _chgsign(double _X); 
#line 502
double __cdecl copysign(double _Number, double _Sign); 
#line 503
double __cdecl _copysign(double _Number, double _Sign); 
#line 504
double __cdecl erf(double _X); 
#line 505
double __cdecl erfc(double _X); 
#line 506
double __cdecl exp2(double _X); 
#line 507
double __cdecl expm1(double _X); 
#line 508
double __cdecl fdim(double _X, double _Y); 
#line 509
double __cdecl floor(double _X); 
#line 510
double __cdecl fma(double _X, double _Y, double _Z); 
#line 511
double __cdecl fmax(double _X, double _Y); 
#line 512
double __cdecl fmin(double _X, double _Y); 
#line 513
double __cdecl frexp(double _X, int * _Y); 
#line 514
double __cdecl hypot(double _X, double _Y); 
#line 515
double __cdecl _hypot(double _X, double _Y); 
#line 516
int __cdecl ilogb(double _X); 
#line 517
double __cdecl ldexp(double _X, int _Y); 
#line 518
double __cdecl lgamma(double _X); 
#line 519
__int64 __cdecl llrint(double _X); 
#line 520
__int64 __cdecl llround(double _X); 
#line 521
double __cdecl log1p(double _X); 
#line 522
double __cdecl log2(double _X); 
#line 523
double __cdecl logb(double _X); 
#line 524
long __cdecl lrint(double _X); 
#line 525
long __cdecl lround(double _X); 
#line 527
int __cdecl _matherr(_exception * _Except); 
#line 529
double __cdecl modf(double _X, double * _Y); 
#line 530
double __cdecl nan(const char * _X); 
#line 531
double __cdecl nearbyint(double _X); 
#line 532
double __cdecl nextafter(double _X, double _Y); 
#line 533
double __cdecl nexttoward(double _X, long double _Y); 
#line 534
double __cdecl remainder(double _X, double _Y); 
#line 535
double __cdecl remquo(double _X, double _Y, int * _Z); 
#line 536
double __cdecl rint(double _X); 
#line 537
double __cdecl round(double _X); 
#line 538
double __cdecl scalbln(double _X, long _Y); 
#line 539
double __cdecl scalbn(double _X, int _Y); 
#line 540
double __cdecl tgamma(double _X); 
#line 541
double __cdecl trunc(double _X); 
#line 542
double __cdecl _j0(double _X); 
#line 543
double __cdecl _j1(double _X); 
#line 544
double __cdecl _jn(int _X, double _Y); 
#line 545
double __cdecl _y0(double _X); 
#line 546
double __cdecl _y1(double _X); 
#line 547
double __cdecl _yn(int _X, double _Y); 
#line 549
float __cdecl acoshf(float _X); 
#line 550
float __cdecl asinhf(float _X); 
#line 551
float __cdecl atanhf(float _X); 
#line 552
float __cdecl cbrtf(float _X); 
#line 553
float __cdecl _chgsignf(float _X); 
#line 554
float __cdecl copysignf(float _Number, float _Sign); 
#line 555
float __cdecl _copysignf(float _Number, float _Sign); 
#line 556
float __cdecl erff(float _X); 
#line 557
float __cdecl erfcf(float _X); 
#line 558
float __cdecl expm1f(float _X); 
#line 559
float __cdecl exp2f(float _X); 
#line 560
float __cdecl fdimf(float _X, float _Y); 
#line 561
float __cdecl fmaf(float _X, float _Y, float _Z); 
#line 562
float __cdecl fmaxf(float _X, float _Y); 
#line 563
float __cdecl fminf(float _X, float _Y); 
#line 564
float __cdecl _hypotf(float _X, float _Y); 
#line 565
int __cdecl ilogbf(float _X); 
#line 566
float __cdecl lgammaf(float _X); 
#line 567
__int64 __cdecl llrintf(float _X); 
#line 568
__int64 __cdecl llroundf(float _X); 
#line 569
float __cdecl log1pf(float _X); 
#line 570
float __cdecl log2f(float _X); 
#line 571
float __cdecl logbf(float _X); 
#line 572
long __cdecl lrintf(float _X); 
#line 573
long __cdecl lroundf(float _X); 
#line 574
float __cdecl nanf(const char * _X); 
#line 575
float __cdecl nearbyintf(float _X); 
#line 576
float __cdecl nextafterf(float _X, float _Y); 
#line 577
float __cdecl nexttowardf(float _X, long double _Y); 
#line 578
float __cdecl remainderf(float _X, float _Y); 
#line 579
float __cdecl remquof(float _X, float _Y, int * _Z); 
#line 580
float __cdecl rintf(float _X); 
#line 581
float __cdecl roundf(float _X); 
#line 582
float __cdecl scalblnf(float _X, long _Y); 
#line 583
float __cdecl scalbnf(float _X, int _Y); 
#line 584
float __cdecl tgammaf(float _X); 
#line 585
float __cdecl truncf(float _X); 
#line 595 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
float __cdecl _logbf(float _X); 
#line 596
float __cdecl _nextafterf(float _X, float _Y); 
#line 597
int __cdecl _finitef(float _X); 
#line 598
int __cdecl _isnanf(float _X); 
#line 599
int __cdecl _fpclassf(float _X); 
#line 601
int __cdecl _set_FMA3_enable(int _Flag); 
#line 602
int __cdecl _get_FMA3_enable(); 
#line 615 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
float __cdecl acosf(float _X); 
#line 616
float __cdecl asinf(float _X); 
#line 617
float __cdecl atan2f(float _Y, float _X); 
#line 618
float __cdecl atanf(float _X); 
#line 619
float __cdecl ceilf(float _X); 
#line 620
float __cdecl cosf(float _X); 
#line 621
float __cdecl coshf(float _X); 
#line 622
float __cdecl expf(float _X); 
#line 674 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
__inline float __cdecl fabsf(float _X) 
#line 675
{ 
#line 676
return (float)fabs(_X); 
#line 677
} 
#line 683 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
float __cdecl floorf(float _X); 
#line 684
float __cdecl fmodf(float _X, float _Y); 
#line 700 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
__inline float __cdecl frexpf(float _X, int *_Y) 
#line 701
{ 
#line 702
return (float)frexp(_X, _Y); 
#line 703
} 
#line 705
__inline float __cdecl hypotf(float _X, float _Y) 
#line 706
{ 
#line 707
return _hypotf(_X, _Y); 
#line 708
} 
#line 710
__inline float __cdecl ldexpf(float _X, int _Y) 
#line 711
{ 
#line 712
return (float)ldexp(_X, _Y); 
#line 713
} 
#line 717
float __cdecl log10f(float _X); 
#line 718
float __cdecl logf(float _X); 
#line 719
float __cdecl modff(float _X, float * _Y); 
#line 720
float __cdecl powf(float _X, float _Y); 
#line 721
float __cdecl sinf(float _X); 
#line 722
float __cdecl sinhf(float _X); 
#line 723
float __cdecl sqrtf(float _X); 
#line 724
float __cdecl tanf(float _X); 
#line 725
float __cdecl tanhf(float _X); 
#line 779 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
long double __cdecl acoshl(long double _X); 
#line 781
__inline long double __cdecl acosl(long double _X) 
#line 782
{ 
#line 783
return acos((double)_X); 
#line 784
} 
#line 786
long double __cdecl asinhl(long double _X); 
#line 788
__inline long double __cdecl asinl(long double _X) 
#line 789
{ 
#line 790
return asin((double)_X); 
#line 791
} 
#line 793
__inline long double __cdecl atan2l(long double _Y, long double _X) 
#line 794
{ 
#line 795
return atan2((double)_Y, (double)_X); 
#line 796
} 
#line 798
long double __cdecl atanhl(long double _X); 
#line 800
__inline long double __cdecl atanl(long double _X) 
#line 801
{ 
#line 802
return atan((double)_X); 
#line 803
} 
#line 805
long double __cdecl cbrtl(long double _X); 
#line 807
__inline long double __cdecl ceill(long double _X) 
#line 808
{ 
#line 809
return ceil((double)_X); 
#line 810
} 
#line 812
__inline long double __cdecl _chgsignl(long double _X) 
#line 813
{ 
#line 814
return _chgsign((double)_X); 
#line 815
} 
#line 817
long double __cdecl copysignl(long double _Number, long double _Sign); 
#line 819
__inline long double __cdecl _copysignl(long double _Number, long double _Sign) 
#line 820
{ 
#line 821
return _copysign((double)_Number, (double)_Sign); 
#line 822
} 
#line 824
__inline long double __cdecl coshl(long double _X) 
#line 825
{ 
#line 826
return cosh((double)_X); 
#line 827
} 
#line 829
__inline long double __cdecl cosl(long double _X) 
#line 830
{ 
#line 831
return cos((double)_X); 
#line 832
} 
#line 834
long double __cdecl erfl(long double _X); 
#line 835
long double __cdecl erfcl(long double _X); 
#line 837
__inline long double __cdecl expl(long double _X) 
#line 838
{ 
#line 839
return exp((double)_X); 
#line 840
} 
#line 842
long double __cdecl exp2l(long double _X); 
#line 843
long double __cdecl expm1l(long double _X); 
#line 845
__inline long double __cdecl fabsl(long double _X) 
#line 846
{ 
#line 847
return fabs((double)_X); 
#line 848
} 
#line 850
long double __cdecl fdiml(long double _X, long double _Y); 
#line 852
__inline long double __cdecl floorl(long double _X) 
#line 853
{ 
#line 854
return floor((double)_X); 
#line 855
} 
#line 857
long double __cdecl fmal(long double _X, long double _Y, long double _Z); 
#line 858
long double __cdecl fmaxl(long double _X, long double _Y); 
#line 859
long double __cdecl fminl(long double _X, long double _Y); 
#line 861
__inline long double __cdecl fmodl(long double _X, long double _Y) 
#line 862
{ 
#line 863
return fmod((double)_X, (double)_Y); 
#line 864
} 
#line 866
__inline long double __cdecl frexpl(long double _X, int *_Y) 
#line 867
{ 
#line 868
return frexp((double)_X, _Y); 
#line 869
} 
#line 871
int __cdecl ilogbl(long double _X); 
#line 873
__inline long double __cdecl _hypotl(long double _X, long double _Y) 
#line 874
{ 
#line 875
return _hypot((double)_X, (double)_Y); 
#line 876
} 
#line 878
__inline long double __cdecl hypotl(long double _X, long double _Y) 
#line 879
{ 
#line 880
return _hypot((double)_X, (double)_Y); 
#line 881
} 
#line 883
__inline long double __cdecl ldexpl(long double _X, int _Y) 
#line 884
{ 
#line 885
return ldexp((double)_X, _Y); 
#line 886
} 
#line 888
long double __cdecl lgammal(long double _X); 
#line 889
__int64 __cdecl llrintl(long double _X); 
#line 890
__int64 __cdecl llroundl(long double _X); 
#line 892
__inline long double __cdecl logl(long double _X) 
#line 893
{ 
#line 894
return log((double)_X); 
#line 895
} 
#line 897
__inline long double __cdecl log10l(long double _X) 
#line 898
{ 
#line 899
return log10((double)_X); 
#line 900
} 
#line 902
long double __cdecl log1pl(long double _X); 
#line 903
long double __cdecl log2l(long double _X); 
#line 904
long double __cdecl logbl(long double _X); 
#line 905
long __cdecl lrintl(long double _X); 
#line 906
long __cdecl lroundl(long double _X); 
#line 908
__inline long double __cdecl modfl(long double _X, long double *_Y) 
#line 909
{ 
#line 910
double _F, _I; 
#line 911
_F = modf((double)_X, &_I); 
#line 912
(*_Y) = _I; 
#line 913
return _F; 
#line 914
} 
#line 916
long double __cdecl nanl(const char * _X); 
#line 917
long double __cdecl nearbyintl(long double _X); 
#line 918
long double __cdecl nextafterl(long double _X, long double _Y); 
#line 919
long double __cdecl nexttowardl(long double _X, long double _Y); 
#line 921
__inline long double __cdecl powl(long double _X, long double _Y) 
#line 922
{ 
#line 923
return pow((double)_X, (double)_Y); 
#line 924
} 
#line 926
long double __cdecl remainderl(long double _X, long double _Y); 
#line 927
long double __cdecl remquol(long double _X, long double _Y, int * _Z); 
#line 928
long double __cdecl rintl(long double _X); 
#line 929
long double __cdecl roundl(long double _X); 
#line 930
long double __cdecl scalblnl(long double _X, long _Y); 
#line 931
long double __cdecl scalbnl(long double _X, int _Y); 
#line 933
__inline long double __cdecl sinhl(long double _X) 
#line 934
{ 
#line 935
return sinh((double)_X); 
#line 936
} 
#line 938
__inline long double __cdecl sinl(long double _X) 
#line 939
{ 
#line 940
return sin((double)_X); 
#line 941
} 
#line 943
__inline long double __cdecl sqrtl(long double _X) 
#line 944
{ 
#line 945
return sqrt((double)_X); 
#line 946
} 
#line 948
__inline long double __cdecl tanhl(long double _X) 
#line 949
{ 
#line 950
return tanh((double)_X); 
#line 951
} 
#line 953
__inline long double __cdecl tanl(long double _X) 
#line 954
{ 
#line 955
return tan((double)_X); 
#line 956
} 
#line 958
long double __cdecl tgammal(long double _X); 
#line 959
long double __cdecl truncl(long double _X); 
#line 980 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
extern double HUGE; 
#line 985 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
double __cdecl j0(double _X); 
#line 986
double __cdecl j1(double _X); 
#line 987
double __cdecl jn(int _X, double _Y); 
#line 988
double __cdecl y0(double _X); 
#line 989
double __cdecl y1(double _X); 
#line 990
double __cdecl yn(int _X, double _Y); 
#line 995 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\corecrt_math.h"
}__pragma( pack ( pop )) 
#line 997
#pragma warning(pop)
#line 12 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#pragma warning(disable: 4985)
#line 17
extern "C++" {
#line 19
#pragma pack ( push, 8 )
#line 33
namespace std { 
#line 35
struct nothrow_t { 
#line 36
explicit nothrow_t() = default;
#line 37
}; 
#line 42
extern const nothrow_t nothrow; 
#line 44 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
}
#line 47 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 48
operator new(size_t _Size); 
#line 52
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 53
operator new(size_t _Size, const std::nothrow_t &) noexcept; 
#line 58
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 59
operator new[](size_t _Size); 
#line 63
[[nodiscard]] __declspec(allocator) void *__cdecl 
#line 64
operator new[](size_t _Size, const std::nothrow_t &) noexcept; 
#line 69
void __cdecl operator delete(void * _Block) noexcept; 
#line 73
void __cdecl operator delete(void * _Block, const std::nothrow_t &) noexcept; 
#line 78
void __cdecl operator delete[](void * _Block) noexcept; 
#line 82
void __cdecl operator delete[](void * _Block, const std::nothrow_t &) noexcept; 
#line 87
void __cdecl operator delete(void * _Block, size_t _Size) noexcept; 
#line 92
void __cdecl operator delete[](void * _Block, size_t _Size) noexcept; 
#line 160
#pragma warning(push)
#pragma warning(disable: 4577)
#pragma warning(disable: 4514)
#line 165
[[nodiscard]] [[msvc::constexpr]] inline void *__cdecl 
#line 166
operator new(size_t _Size, void *
#line 167
_Where) noexcept 
#line 168
{ 
#line 169
(void)_Size; 
#line 170
return _Where; 
#line 171
} 
#line 173
inline void __cdecl operator delete(void *, void *) noexcept 
#line 174
{ 
#line 176
} 
#line 181 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
[[nodiscard]] inline void *__cdecl 
#line 182
operator new[](size_t _Size, void *
#line 183
_Where) noexcept 
#line 184
{ 
#line 185
(void)_Size; 
#line 186
return _Where; 
#line 187
} 
#line 189
inline void __cdecl operator delete[](void *, void *) noexcept 
#line 190
{ 
#line 191
} 
#line 199 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
}
#line 193
#pragma warning(pop)
#line 197
#pragma pack ( pop )
#line 202 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new.h"
#pragma warning(pop)
#line 12 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new_debug.h"
#pragma warning(push)
#pragma warning(disable: 4514 4820 )
#line 16
extern "C++" {
#line 18
#pragma pack ( push, 8 )
#line 25
[[nodiscard]] 
#line 26
__declspec(allocator) void *__cdecl operator new(size_t _Size, int _BlockUse, const char * _FileName, int _LineNumber); 
#line 33
[[nodiscard]] 
#line 34
__declspec(allocator) void *__cdecl operator new[](size_t _Size, int _BlockUse, const char * _FileName, int _LineNumber); 
#line 41
void __cdecl operator delete(void * _Block, int _BlockUse, const char * _FileName, int _LineNumber) noexcept; 
#line 48
void __cdecl operator delete[](void * _Block, int _BlockUse, const char * _FileName, int _LineNumber) noexcept; 
#line 61 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new_debug.h"
}
#line 59
#pragma pack ( pop )
#line 64 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\vcruntime_new_debug.h"
#pragma warning(pop)
#line 15 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\crtdbg.h"
#pragma warning(push)
#pragma warning(disable: 4324 4514 4574 4710 4793 4820 4995 4996 28719 28726 28727 )
#line 19
__pragma( pack ( push, 8 )) extern "C" {
#line 23
typedef void *_HFILE; 
#line 49
typedef int (__cdecl *_CRT_REPORT_HOOK)(int, char *, int *); 
#line 50
typedef int (__cdecl *_CRT_REPORT_HOOKW)(int, __wchar_t *, int *); 
#line 56
typedef int (__cdecl *_CRT_ALLOC_HOOK)(int, void *, size_t, int, long, const unsigned char *, int); 
#line 112
typedef void (__cdecl *_CRT_DUMP_CLIENT)(void *, size_t); 
#line 118
struct _CrtMemBlockHeader; 
#line 127
typedef 
#line 120
struct _CrtMemState { 
#line 122
_CrtMemBlockHeader *pBlockHeader; 
#line 123
size_t lCounts[5]; 
#line 124
size_t lSizes[5]; 
#line 125
size_t lHighWaterCount; 
#line 126
size_t lTotalCount; 
#line 127
} _CrtMemState; 
#line 813 "C:\\Program Files (x86)\\Windows Kits\\10\\include\\10.0.22000.0\\ucrt\\crtdbg.h"
}__pragma( pack ( pop )) 
#line 815
#pragma warning(pop)
#line 20 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4988 5026 5027 5045 6294 4984 5053 )
#line 138 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
#pragma detect_mismatch("_MSC_VER", "1900")
#line 142 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
#pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", "0")
#line 147 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
#pragma detect_mismatch("RuntimeLibrary", "MT_StaticRelease")
#line 49 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\use_ansi.h"
#pragma comment(lib, "libcpmt")
#line 346 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
namespace std { 
#line 347
enum _Uninitialized { 
#line 348
_Noinit
#line 349
}; 
#line 351
class _Lockit { 
#line 367
public: __thiscall _Lockit() noexcept; 
#line 368
explicit __thiscall _Lockit(int) noexcept; 
#line 369
__thiscall ~_Lockit() noexcept; 
#line 372 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
static void __cdecl _Lockit_ctor(int) noexcept; 
#line 373
static void __cdecl _Lockit_dtor(int) noexcept; 
#line 376
private: static void __cdecl _Lockit_ctor(_Lockit *) noexcept; 
#line 377
static void __cdecl _Lockit_ctor(_Lockit *, int) noexcept; 
#line 378
static void __cdecl _Lockit_dtor(_Lockit *) noexcept; 
#line 381
public: _Lockit(const _Lockit &) = delete;
#line 382
_Lockit &operator=(const _Lockit &) = delete;
#line 385
private: int _Locktype; 
#line 386
}; 
#line 505 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\yvals.h"
}
#line 509
#pragma warning(pop)
#pragma pack ( pop )
#line 15 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cstdlib"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4988 5026 5027 5045 6294 4984 5053 )
#line 23
[[nodiscard]] inline double abs(double _Xx) noexcept { 
#line 24
return ::fabs(_Xx); 
#line 25
} 
#line 27
[[nodiscard]] inline float abs(float _Xx) noexcept { 
#line 28
return ::fabsf(_Xx); 
#line 29
} 
#line 31
[[nodiscard]] inline long double abs(long double _Xx) noexcept { 
#line 32
return ::fabsl(_Xx); 
#line 33
} 
#line 35
namespace std { 
#line 36
using ::size_t;
#line 37
using ::div_t;
#line 38
using ::ldiv_t;
#line 39
using ::abort;
#line 40
using ::abs;
#line 41
using ::atexit;
#line 42
using ::atof;
#line 43
using ::atoi;
#line 44
using ::atol;
#line 45
using ::bsearch;
#line 46
using ::calloc;
#line 47
using ::div;
#line 48
using ::exit;
#line 49
using ::free;
#line 50
using ::labs;
#line 51
using ::ldiv;
#line 52
using ::malloc;
#line 53
using ::mblen;
#line 54
using ::mbstowcs;
#line 55
using ::mbtowc;
#line 56
using ::qsort;
#line 57
using ::rand;
#line 58
using ::realloc;
#line 59
using ::srand;
#line 60
using ::strtod;
#line 61
using ::strtol;
#line 62
using ::strtoul;
#line 63
using ::wcstombs;
#line 64
using ::wctomb;
#line 66
using ::lldiv_t;
#line 68
using ::getenv;
#line 69
using ::system;
#line 71
using ::atoll;
#line 72
using ::llabs;
#line 73
using ::lldiv;
#line 74
using ::strtof;
#line 75
using ::strtold;
#line 76
using ::strtoll;
#line 77
using ::strtoull;
#line 79
using ::_Exit;
#line 80
using ::at_quick_exit;
#line 81
using ::quick_exit;
#line 82
}
#line 86
#pragma warning(pop)
#pragma pack ( pop )
#line 12 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\xtr1common"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4988 5026 5027 5045 6294 4984 5053 )
#line 19
namespace std { 
#line 20
template < class _Ty, _Ty _Val >
struct integral_constant {
    static constexpr _Ty value = _Val;

    using value_type = _Ty;
    using type = integral_constant;

    constexpr operator value_type ( ) const noexcept {
        return value;
    }

    [ [ nodiscard ] ] constexpr value_type operator ( ) ( ) const noexcept {
        return value;
    }
};
#line 36
template< bool _Val> using bool_constant = integral_constant< bool, _Val> ; 
#line 39
using true_type = bool_constant< true> ; 
#line 40
using false_type = bool_constant< false> ; 
#line 42
template< bool _Test, class _Ty = void> 
#line 43
struct enable_if { }; 
#line 45
template< class _Ty> 
#line 46
struct enable_if< true, _Ty>  { 
#line 47
using type = _Ty; 
#line 48
}; 
#line 50
template< bool _Test, class _Ty = void> using enable_if_t = typename enable_if< _Test, _Ty> ::type; 
#line 53
template< bool _Test, class _Ty1, class _Ty2> 
#line 54
struct conditional { 
#line 55
using type = _Ty1; 
#line 56
}; 
#line 58
template< class _Ty1, class _Ty2> 
#line 59
struct conditional< false, _Ty1, _Ty2>  { 
#line 60
using type = _Ty2; 
#line 61
}; 
#line 63
template< bool _Test, class _Ty1, class _Ty2> using conditional_t = typename conditional< _Test, _Ty1, _Ty2> ::type; 
#line 73
template< class , class > constexpr bool 
#line 74
is_same_v = false; 
#line 75
template< class _Ty> constexpr bool 
#line 76
is_same_v< _Ty, _Ty>  = true; 
#line 78
template< class _Ty1, class _Ty2> 
#line 79
struct is_same : public bool_constant< is_same_v< _Ty1, _Ty2> >  { }; 
#line 82 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\xtr1common"
template< class _Ty> 
#line 83
struct remove_const { 
#line 84
using type = _Ty; 
#line 85
}; 
#line 87
template< class _Ty> 
#line 88
struct remove_const< const _Ty>  { 
#line 89
using type = _Ty; 
#line 90
}; 
#line 92
template< class _Ty> using remove_const_t = typename remove_const< _Ty> ::type; 
#line 95
template< class _Ty> 
#line 96
struct remove_volatile { 
#line 97
using type = _Ty; 
#line 98
}; 
#line 100
template< class _Ty> 
#line 101
struct remove_volatile< volatile _Ty>  { 
#line 102
using type = _Ty; 
#line 103
}; 
#line 105
template< class _Ty> using remove_volatile_t = typename remove_volatile< _Ty> ::type; 
#line 108
template< class _Ty> 
#line 109
struct remove_cv { 
#line 110
using type = _Ty; 
#line 112
template< template< class >  class _Fn> using _Apply = _Fn< _Ty> ; 
#line 114
}; 
#line 116
template< class _Ty> 
#line 117
struct remove_cv< const _Ty>  { 
#line 118
using type = _Ty; 
#line 120
template< template< class >  class _Fn> using _Apply = const _Fn< _Ty> ; 
#line 122
}; 
#line 124
template< class _Ty> 
#line 125
struct remove_cv< volatile _Ty>  { 
#line 126
using type = _Ty; 
#line 128
template< template< class >  class _Fn> using _Apply = volatile _Fn< _Ty> ; 
#line 130
}; 
#line 132
template< class _Ty> 
#line 133
struct remove_cv< const volatile _Ty>  { 
#line 134
using type = _Ty; 
#line 136
template< template< class >  class _Fn> using _Apply = const volatile _Fn< _Ty> ; 
#line 138
}; 
#line 140
template< class _Ty> using remove_cv_t = typename remove_cv< _Ty> ::type; 
#line 143
template< bool _First_value, class _First, class ..._Rest> 
#line 144
struct _Disjunction { 
#line 145
using type = _First; 
#line 146
}; 
#line 148
template< class _False, class _Next, class ..._Rest> 
#line 149
struct _Disjunction< false, _False, _Next, _Rest...>  { 
#line 150
using type = typename std::_Disjunction< _Next::value, _Next, _Rest...> ::type; 
#line 151
}; 
#line 153
template< class ..._Traits> 
#line 154
struct disjunction : public false_type { }; 
#line 156
template< class _First, class ..._Rest> 
#line 157
struct disjunction< _First, _Rest...>  : public _Disjunction< _First::value, _First, _Rest...> ::type { 
#line 159
}; 
#line 161
template< class ..._Traits> constexpr bool 
#line 162
disjunction_v = (disjunction< _Traits...> ::value); 
#line 164
template< class _Ty, class ..._Types> constexpr bool 
#line 165
_Is_any_of_v = disjunction_v< is_same< _Ty, _Types> ...> ; 
#line 168
[[nodiscard]] constexpr bool _Is_constant_evaluated() noexcept { 
#line 169
return __builtin_is_constant_evaluated(); 
#line 170
} 
#line 178 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\xtr1common"
template< class _Ty> constexpr bool 
#line 179
is_integral_v = _Is_any_of_v< remove_cv_t< _Ty> , bool, char, signed char, unsigned char, __wchar_t, char16_t, char32_t, short, unsigned short, int, unsigned, long, unsigned long, __int64, unsigned __int64> ; 
#line 186
template< class _Ty> 
#line 187
struct is_integral : public bool_constant< is_integral_v< _Ty> >  { }; 
#line 189
template< class _Ty> constexpr bool 
#line 190
is_floating_point_v = _Is_any_of_v< remove_cv_t< _Ty> , float, double, long double> ; 
#line 192
template< class _Ty> 
#line 193
struct is_floating_point : public bool_constant< is_floating_point_v< _Ty> >  { }; 
#line 195
template< class _Ty> constexpr bool 
#line 196
is_arithmetic_v = is_integral_v< _Ty>  || is_floating_point_v< _Ty> ; 
#line 199
template< class _Ty> 
#line 200
struct is_arithmetic : public bool_constant< is_arithmetic_v< _Ty> >  { }; 
#line 202
template< class _Ty> 
#line 203
struct remove_reference { 
#line 204
using type = _Ty; 
#line 205
using _Const_thru_ref_type = const _Ty; 
#line 206
}; 
#line 208
template< class _Ty> 
#line 209
struct remove_reference< _Ty &>  { 
#line 210
using type = _Ty; 
#line 211
using _Const_thru_ref_type = const _Ty &; 
#line 212
}; 
#line 214
template< class _Ty> 
#line 215
struct remove_reference< _Ty &&>  { 
#line 216
using type = _Ty; 
#line 217
using _Const_thru_ref_type = const _Ty &&; 
#line 218
}; 
#line 220
template< class _Ty> using remove_reference_t = typename remove_reference< _Ty> ::type; 
#line 223
template< class _Ty> using _Const_thru_ref = typename remove_reference< _Ty> ::_Const_thru_ref_type; 
#line 226
template< class _Ty> using _Remove_cvref_t = remove_cv_t< remove_reference_t< _Ty> > ; 
#line 239 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\xtr1common"
}
#line 242
#pragma warning(pop)
#pragma pack ( pop )
#line 30 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
#pragma pack ( push, 8 )
#pragma warning(push, 3)
#pragma warning(disable : 4180 4412 4455 4494 4514 4574 4582 4583 4587 4588 4619 4623 4625 4626 4643 4648 4702 4793 4820 4988 5026 5027 5045 6294 4984 5053 )
#line 37
[[nodiscard]] inline float acos(float _Xx) noexcept { 
#line 38
return ::acosf(_Xx); 
#line 39
} 
#line 41
[[nodiscard]] inline float acosh(float _Xx) noexcept { 
#line 42
return ::acoshf(_Xx); 
#line 43
} 
#line 45
[[nodiscard]] inline float asin(float _Xx) noexcept { 
#line 46
return ::asinf(_Xx); 
#line 47
} 
#line 49
[[nodiscard]] inline float asinh(float _Xx) noexcept { 
#line 50
return ::asinhf(_Xx); 
#line 51
} 
#line 53
[[nodiscard]] inline float atan(float _Xx) noexcept { 
#line 54
return ::atanf(_Xx); 
#line 55
} 
#line 57
[[nodiscard]] inline float atanh(float _Xx) noexcept { 
#line 58
return ::atanhf(_Xx); 
#line 59
} 
#line 61
[[nodiscard]] inline float atan2(float _Yx, float _Xx) noexcept { 
#line 62
return ::atan2f(_Yx, _Xx); 
#line 63
} 
#line 65
[[nodiscard]] inline float cbrt(float _Xx) noexcept { 
#line 66
return ::cbrtf(_Xx); 
#line 67
} 
#line 69
[[nodiscard]] inline float ceil(float _Xx) noexcept { 
#line 75 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::ceilf(_Xx); 
#line 77 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 79
[[nodiscard]] inline float copysign(float _Number, float _Sign) noexcept { 
#line 85 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::copysignf(_Number, _Sign); 
#line 87 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 89
[[nodiscard]] inline float cos(float _Xx) noexcept { 
#line 90
return ::cosf(_Xx); 
#line 91
} 
#line 93
[[nodiscard]] inline float cosh(float _Xx) noexcept { 
#line 94
return ::coshf(_Xx); 
#line 95
} 
#line 97
[[nodiscard]] inline float erf(float _Xx) noexcept { 
#line 98
return ::erff(_Xx); 
#line 99
} 
#line 101
[[nodiscard]] inline float erfc(float _Xx) noexcept { 
#line 102
return ::erfcf(_Xx); 
#line 103
} 
#line 105
[[nodiscard]] inline float exp(float _Xx) noexcept { 
#line 106
return ::expf(_Xx); 
#line 107
} 
#line 109
[[nodiscard]] inline float exp2(float _Xx) noexcept { 
#line 110
return ::exp2f(_Xx); 
#line 111
} 
#line 113
[[nodiscard]] inline float expm1(float _Xx) noexcept { 
#line 114
return ::expm1f(_Xx); 
#line 115
} 
#line 117
[[nodiscard]] inline float fabs(float _Xx) noexcept { 
#line 118
return ::fabsf(_Xx); 
#line 119
} 
#line 121
[[nodiscard]] inline float fdim(float _Xx, float _Yx) noexcept { 
#line 122
return ::fdimf(_Xx, _Yx); 
#line 123
} 
#line 125
[[nodiscard]] inline float floor(float _Xx) noexcept { 
#line 131 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::floorf(_Xx); 
#line 133 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 135
[[nodiscard]] inline float fma(float _Xx, float _Yx, float _Zx) noexcept { 
#line 136
return ::fmaf(_Xx, _Yx, _Zx); 
#line 137
} 
#line 139
[[nodiscard]] inline float fmax(float _Xx, float _Yx) noexcept { 
#line 140
return ::fmaxf(_Xx, _Yx); 
#line 141
} 
#line 143
[[nodiscard]] inline float fmin(float _Xx, float _Yx) noexcept { 
#line 144
return ::fminf(_Xx, _Yx); 
#line 145
} 
#line 147
[[nodiscard]] inline float fmod(float _Xx, float _Yx) noexcept { 
#line 148
return ::fmodf(_Xx, _Yx); 
#line 149
} 
#line 151
inline float frexp(float _Xx, int *_Yx) noexcept { 
#line 152
return ::frexpf(_Xx, _Yx); 
#line 153
} 
#line 155
[[nodiscard]] inline float hypot(float _Xx, float _Yx) noexcept { 
#line 156
return ::hypotf(_Xx, _Yx); 
#line 157
} 
#line 159
[[nodiscard]] inline int ilogb(float _Xx) noexcept { 
#line 160
return ::ilogbf(_Xx); 
#line 161
} 
#line 163
[[nodiscard]] inline float ldexp(float _Xx, int _Yx) noexcept { 
#line 164
return ::ldexpf(_Xx, _Yx); 
#line 165
} 
#line 167
[[nodiscard]] inline float lgamma(float _Xx) noexcept { 
#line 168
return ::lgammaf(_Xx); 
#line 169
} 
#line 171
[[nodiscard]] inline __int64 llrint(float _Xx) noexcept { 
#line 172
return ::llrintf(_Xx); 
#line 173
} 
#line 175
[[nodiscard]] inline __int64 llround(float _Xx) noexcept { 
#line 176
return ::llroundf(_Xx); 
#line 177
} 
#line 179
[[nodiscard]] inline float log(float _Xx) noexcept { 
#line 180
return ::logf(_Xx); 
#line 181
} 
#line 183
[[nodiscard]] inline float log10(float _Xx) noexcept { 
#line 184
return ::log10f(_Xx); 
#line 185
} 
#line 187
[[nodiscard]] inline float log1p(float _Xx) noexcept { 
#line 188
return ::log1pf(_Xx); 
#line 189
} 
#line 191
[[nodiscard]] inline float log2(float _Xx) noexcept { 
#line 192
return ::log2f(_Xx); 
#line 193
} 
#line 195
[[nodiscard]] inline float logb(float _Xx) noexcept { 
#line 196
return ::logbf(_Xx); 
#line 197
} 
#line 199
[[nodiscard]] inline long lrint(float _Xx) noexcept { 
#line 200
return ::lrintf(_Xx); 
#line 201
} 
#line 203
[[nodiscard]] inline long lround(float _Xx) noexcept { 
#line 204
return ::lroundf(_Xx); 
#line 205
} 
#line 207
inline float modf(float _Xx, float *_Yx) noexcept { 
#line 208
return ::modff(_Xx, _Yx); 
#line 209
} 
#line 211
[[nodiscard]] inline float nearbyint(float _Xx) noexcept { 
#line 212
return ::nearbyintf(_Xx); 
#line 213
} 
#line 215
[[nodiscard]] inline float nextafter(float _Xx, float _Yx) noexcept { 
#line 216
return ::nextafterf(_Xx, _Yx); 
#line 217
} 
#line 219
[[nodiscard]] inline float nexttoward(float _Xx, long double _Yx) noexcept { 
#line 220
return ::nexttowardf(_Xx, _Yx); 
#line 221
} 
#line 223
[[nodiscard]] inline float pow(float _Xx, float _Yx) noexcept { 
#line 224
return ::powf(_Xx, _Yx); 
#line 225
} 
#line 227
[[nodiscard]] inline float remainder(float _Xx, float _Yx) noexcept { 
#line 228
return ::remainderf(_Xx, _Yx); 
#line 229
} 
#line 231
inline float remquo(float _Xx, float _Yx, int *_Zx) noexcept { 
#line 232
return ::remquof(_Xx, _Yx, _Zx); 
#line 233
} 
#line 235
[[nodiscard]] inline float rint(float _Xx) noexcept { 
#line 236
return ::rintf(_Xx); 
#line 237
} 
#line 239
[[nodiscard]] inline float round(float _Xx) noexcept { 
#line 245 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::roundf(_Xx); 
#line 247 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 249
[[nodiscard]] inline float scalbln(float _Xx, long _Yx) noexcept { 
#line 250
return ::scalblnf(_Xx, _Yx); 
#line 251
} 
#line 253
[[nodiscard]] inline float scalbn(float _Xx, int _Yx) noexcept { 
#line 254
return ::scalbnf(_Xx, _Yx); 
#line 255
} 
#line 257
[[nodiscard]] inline float sin(float _Xx) noexcept { 
#line 258
return ::sinf(_Xx); 
#line 259
} 
#line 261
[[nodiscard]] inline float sinh(float _Xx) noexcept { 
#line 262
return ::sinhf(_Xx); 
#line 263
} 
#line 265
[[nodiscard]] inline float sqrt(float _Xx) noexcept { 
#line 266
return ::sqrtf(_Xx); 
#line 267
} 
#line 269
[[nodiscard]] inline float tan(float _Xx) noexcept { 
#line 270
return ::tanf(_Xx); 
#line 271
} 
#line 273
[[nodiscard]] inline float tanh(float _Xx) noexcept { 
#line 274
return ::tanhf(_Xx); 
#line 275
} 
#line 277
[[nodiscard]] inline float tgamma(float _Xx) noexcept { 
#line 278
return ::tgammaf(_Xx); 
#line 279
} 
#line 281
[[nodiscard]] inline float trunc(float _Xx) noexcept { 
#line 287 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::truncf(_Xx); 
#line 289 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 291
[[nodiscard]] inline long double acos(long double _Xx) noexcept { 
#line 292
return ::acosl(_Xx); 
#line 293
} 
#line 295
[[nodiscard]] inline long double acosh(long double _Xx) noexcept { 
#line 296
return ::acoshl(_Xx); 
#line 297
} 
#line 299
[[nodiscard]] inline long double asin(long double _Xx) noexcept { 
#line 300
return ::asinl(_Xx); 
#line 301
} 
#line 303
[[nodiscard]] inline long double asinh(long double _Xx) noexcept { 
#line 304
return ::asinhl(_Xx); 
#line 305
} 
#line 307
[[nodiscard]] inline long double atan(long double _Xx) noexcept { 
#line 308
return ::atanl(_Xx); 
#line 309
} 
#line 311
[[nodiscard]] inline long double atanh(long double _Xx) noexcept { 
#line 312
return ::atanhl(_Xx); 
#line 313
} 
#line 315
[[nodiscard]] inline long double atan2(long double _Yx, long double _Xx) noexcept 
#line 316
{ 
#line 317
return ::atan2l(_Yx, _Xx); 
#line 318
} 
#line 320
[[nodiscard]] inline long double cbrt(long double _Xx) noexcept { 
#line 321
return ::cbrtl(_Xx); 
#line 322
} 
#line 324
[[nodiscard]] inline long double ceil(long double _Xx) noexcept { 
#line 330 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::ceill(_Xx); 
#line 332 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 334
[[nodiscard]] inline long double copysign(long double _Number, long double _Sign) noexcept 
#line 335
{ 
#line 341 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::copysignl(_Number, _Sign); 
#line 343 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 345
[[nodiscard]] inline long double cos(long double _Xx) noexcept { 
#line 346
return ::cosl(_Xx); 
#line 347
} 
#line 349
[[nodiscard]] inline long double cosh(long double _Xx) noexcept { 
#line 350
return ::coshl(_Xx); 
#line 351
} 
#line 353
[[nodiscard]] inline long double erf(long double _Xx) noexcept { 
#line 354
return ::erfl(_Xx); 
#line 355
} 
#line 357
[[nodiscard]] inline long double erfc(long double _Xx) noexcept { 
#line 358
return ::erfcl(_Xx); 
#line 359
} 
#line 361
[[nodiscard]] inline long double exp(long double _Xx) noexcept { 
#line 362
return ::expl(_Xx); 
#line 363
} 
#line 365
[[nodiscard]] inline long double exp2(long double _Xx) noexcept { 
#line 366
return ::exp2l(_Xx); 
#line 367
} 
#line 369
[[nodiscard]] inline long double expm1(long double _Xx) noexcept { 
#line 370
return ::expm1l(_Xx); 
#line 371
} 
#line 373
[[nodiscard]] inline long double fabs(long double _Xx) noexcept { 
#line 374
return ::fabsl(_Xx); 
#line 375
} 
#line 377
[[nodiscard]] inline long double fdim(long double _Xx, long double _Yx) noexcept 
#line 378
{ 
#line 379
return ::fdiml(_Xx, _Yx); 
#line 380
} 
#line 382
[[nodiscard]] inline long double floor(long double _Xx) noexcept { 
#line 388 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::floorl(_Xx); 
#line 390 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 392
[[nodiscard]] inline long double fma(long double 
#line 393
_Xx, long double _Yx, long double _Zx) noexcept { 
#line 394
return ::fmal(_Xx, _Yx, _Zx); 
#line 395
} 
#line 397
[[nodiscard]] inline long double fmax(long double _Xx, long double _Yx) noexcept 
#line 398
{ 
#line 399
return ::fmaxl(_Xx, _Yx); 
#line 400
} 
#line 402
[[nodiscard]] inline long double fmin(long double _Xx, long double _Yx) noexcept 
#line 403
{ 
#line 404
return ::fminl(_Xx, _Yx); 
#line 405
} 
#line 407
[[nodiscard]] inline long double fmod(long double _Xx, long double _Yx) noexcept 
#line 408
{ 
#line 409
return ::fmodl(_Xx, _Yx); 
#line 410
} 
#line 412
inline long double frexp(long double _Xx, int *_Yx) noexcept { 
#line 413
return ::frexpl(_Xx, _Yx); 
#line 414
} 
#line 416
[[nodiscard]] inline long double hypot(long double _Xx, long double _Yx) noexcept 
#line 417
{ 
#line 418
return ::hypotl(_Xx, _Yx); 
#line 419
} 
#line 421
[[nodiscard]] inline int ilogb(long double _Xx) noexcept { 
#line 422
return ::ilogbl(_Xx); 
#line 423
} 
#line 425
[[nodiscard]] inline long double ldexp(long double _Xx, int _Yx) noexcept { 
#line 426
return ::ldexpl(_Xx, _Yx); 
#line 427
} 
#line 429
[[nodiscard]] inline long double lgamma(long double _Xx) noexcept { 
#line 430
return ::lgammal(_Xx); 
#line 431
} 
#line 433
[[nodiscard]] inline __int64 llrint(long double _Xx) noexcept { 
#line 434
return ::llrintl(_Xx); 
#line 435
} 
#line 437
[[nodiscard]] inline __int64 llround(long double _Xx) noexcept { 
#line 438
return ::llroundl(_Xx); 
#line 439
} 
#line 441
[[nodiscard]] inline long double log(long double _Xx) noexcept { 
#line 442
return ::logl(_Xx); 
#line 443
} 
#line 445
[[nodiscard]] inline long double log10(long double _Xx) noexcept { 
#line 446
return ::log10l(_Xx); 
#line 447
} 
#line 449
[[nodiscard]] inline long double log1p(long double _Xx) noexcept { 
#line 450
return ::log1pl(_Xx); 
#line 451
} 
#line 453
[[nodiscard]] inline long double log2(long double _Xx) noexcept { 
#line 454
return ::log2l(_Xx); 
#line 455
} 
#line 457
[[nodiscard]] inline long double logb(long double _Xx) noexcept { 
#line 458
return ::logbl(_Xx); 
#line 459
} 
#line 461
[[nodiscard]] inline long lrint(long double _Xx) noexcept { 
#line 462
return ::lrintl(_Xx); 
#line 463
} 
#line 465
[[nodiscard]] inline long lround(long double _Xx) noexcept { 
#line 466
return ::lroundl(_Xx); 
#line 467
} 
#line 469
inline long double modf(long double _Xx, long double *_Yx) noexcept { 
#line 470
return ::modfl(_Xx, _Yx); 
#line 471
} 
#line 473
[[nodiscard]] inline long double nearbyint(long double _Xx) noexcept { 
#line 474
return ::nearbyintl(_Xx); 
#line 475
} 
#line 477
[[nodiscard]] inline long double nextafter(long double _Xx, long double _Yx) noexcept 
#line 478
{ 
#line 479
return ::nextafterl(_Xx, _Yx); 
#line 480
} 
#line 482
[[nodiscard]] inline long double nexttoward(long double _Xx, long double _Yx) noexcept 
#line 483
{ 
#line 484
return ::nexttowardl(_Xx, _Yx); 
#line 485
} 
#line 487
[[nodiscard]] inline long double pow(long double _Xx, long double _Yx) noexcept 
#line 488
{ 
#line 489
return ::powl(_Xx, _Yx); 
#line 490
} 
#line 492
[[nodiscard]] inline long double remainder(long double _Xx, long double _Yx) noexcept 
#line 493
{ 
#line 494
return ::remainderl(_Xx, _Yx); 
#line 495
} 
#line 497
inline long double remquo(long double _Xx, long double _Yx, int *_Zx) noexcept { 
#line 498
return ::remquol(_Xx, _Yx, _Zx); 
#line 499
} 
#line 501
[[nodiscard]] inline long double rint(long double _Xx) noexcept { 
#line 502
return ::rintl(_Xx); 
#line 503
} 
#line 505
[[nodiscard]] inline long double round(long double _Xx) noexcept { 
#line 511 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::roundl(_Xx); 
#line 513 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 515
[[nodiscard]] inline long double scalbln(long double _Xx, long _Yx) noexcept { 
#line 516
return ::scalblnl(_Xx, _Yx); 
#line 517
} 
#line 519
[[nodiscard]] inline long double scalbn(long double _Xx, int _Yx) noexcept { 
#line 520
return ::scalbnl(_Xx, _Yx); 
#line 521
} 
#line 523
[[nodiscard]] inline long double sin(long double _Xx) noexcept { 
#line 524
return ::sinl(_Xx); 
#line 525
} 
#line 527
[[nodiscard]] inline long double sinh(long double _Xx) noexcept { 
#line 528
return ::sinhl(_Xx); 
#line 529
} 
#line 531
[[nodiscard]] inline long double sqrt(long double _Xx) noexcept { 
#line 532
return ::sqrtl(_Xx); 
#line 533
} 
#line 535
[[nodiscard]] inline long double tan(long double _Xx) noexcept { 
#line 536
return ::tanl(_Xx); 
#line 537
} 
#line 539
[[nodiscard]] inline long double tanh(long double _Xx) noexcept { 
#line 540
return ::tanhl(_Xx); 
#line 541
} 
#line 543
[[nodiscard]] inline long double tgamma(long double _Xx) noexcept { 
#line 544
return ::tgammal(_Xx); 
#line 545
} 
#line 547
[[nodiscard]] inline long double trunc(long double _Xx) noexcept { 
#line 553 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
return ::truncl(_Xx); 
#line 555 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
} 
#line 558
namespace std { 
#line 559
template< class _Ty1, class _Ty2> using _Common_float_type_t = conditional_t< is_same_v< _Ty1, long double>  || is_same_v< _Ty2, long double> , long double, conditional_t< is_same_v< _Ty1, float>  && is_same_v< _Ty2, float> , float, double> > ; 
#line 563
}
#line 565
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 >
double frexp ( _Ty _Value, int * const _Exp ) noexcept {
    return :: frexp ( static_cast < double > ( _Value ), _Exp );
}
#line 570
template < class _Ty1, class _Ty2, class _Ty3,
    :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 > && :: std :: is_arithmetic_v < _Ty3 >, int > = 0 >
[ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, :: std :: _Common_float_type_t < _Ty2, _Ty3 > > fma (
    _Ty1 _Left, _Ty2 _Middle, _Ty3 _Right ) noexcept {
    using _Common = :: std :: _Common_float_type_t < _Ty1, :: std :: _Common_float_type_t < _Ty2, _Ty3 >>;
    if constexpr ( :: std :: is_same_v < _Common, float > ) {
        return :: fmaf ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    } else if constexpr ( :: std :: is_same_v < _Common, double > ) {
        return :: fma ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    } else {
        return :: fmal ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Middle ), static_cast < _Common > ( _Right ) );
    }
}
#line 584
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 >
:: std :: _Common_float_type_t < _Ty1, _Ty2 > remquo ( _Ty1 _Left, _Ty2 _Right, int * _Pquo ) noexcept {
    using _Common = :: std :: _Common_float_type_t < _Ty1, _Ty2 >;
    if constexpr ( :: std :: is_same_v < _Common, float > ) {
        return :: remquof ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    } else if constexpr ( :: std :: is_same_v < _Common, double > ) {
        return :: remquo ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    } else {
        return :: remquol ( static_cast < _Common > ( _Left ), static_cast < _Common > ( _Right ), _Pquo );
    }
}
#line 643 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double acos ( _Ty _Left ) noexcept { return :: acos ( static_cast < double > ( _Left ) ); }
#line 644
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double asin ( _Ty _Left ) noexcept { return :: asin ( static_cast < double > ( _Left ) ); }
#line 645
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double atan ( _Ty _Left ) noexcept { return :: atan ( static_cast < double > ( _Left ) ); }
#line 646
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > atan2 ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: atan2 ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 647
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cos ( _Ty _Left ) noexcept { return :: cos ( static_cast < double > ( _Left ) ); }
#line 648
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sin ( _Ty _Left ) noexcept { return :: sin ( static_cast < double > ( _Left ) ); }
#line 649
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tan ( _Ty _Left ) noexcept { return :: tan ( static_cast < double > ( _Left ) ); }
#line 650
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double acosh ( _Ty _Left ) noexcept { return :: acosh ( static_cast < double > ( _Left ) ); }
#line 651
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double asinh ( _Ty _Left ) noexcept { return :: asinh ( static_cast < double > ( _Left ) ); }
#line 652
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double atanh ( _Ty _Left ) noexcept { return :: atanh ( static_cast < double > ( _Left ) ); }
#line 653
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cosh ( _Ty _Left ) noexcept { return :: cosh ( static_cast < double > ( _Left ) ); }
#line 654
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sinh ( _Ty _Left ) noexcept { return :: sinh ( static_cast < double > ( _Left ) ); }
#line 655
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tanh ( _Ty _Left ) noexcept { return :: tanh ( static_cast < double > ( _Left ) ); }
#line 656
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double exp ( _Ty _Left ) noexcept { return :: exp ( static_cast < double > ( _Left ) ); }
#line 657
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double exp2 ( _Ty _Left ) noexcept { return :: exp2 ( static_cast < double > ( _Left ) ); }
#line 658
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double expm1 ( _Ty _Left ) noexcept { return :: expm1 ( static_cast < double > ( _Left ) ); }
#line 660
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] int ilogb ( _Ty _Left ) noexcept { return :: ilogb ( static_cast < double > ( _Left ) ); }
#line 661
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double ldexp ( _Ty _Left, int _Arg2 ) noexcept { return :: ldexp ( static_cast < double > ( _Left ), _Arg2 ); }
#line 662
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log ( _Ty _Left ) noexcept { return :: log ( static_cast < double > ( _Left ) ); }
#line 663
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log10 ( _Ty _Left ) noexcept { return :: log10 ( static_cast < double > ( _Left ) ); }
#line 664
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log1p ( _Ty _Left ) noexcept { return :: log1p ( static_cast < double > ( _Left ) ); }
#line 665
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double log2 ( _Ty _Left ) noexcept { return :: log2 ( static_cast < double > ( _Left ) ); }
#line 666
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double logb ( _Ty _Left ) noexcept { return :: logb ( static_cast < double > ( _Left ) ); }
#line 668
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double scalbn ( _Ty _Left, int _Arg2 ) noexcept { return :: scalbn ( static_cast < double > ( _Left ), _Arg2 ); }
#line 669
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double scalbln ( _Ty _Left, long _Arg2 ) noexcept { return :: scalbln ( static_cast < double > ( _Left ), _Arg2 ); }
#line 670
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double cbrt ( _Ty _Left ) noexcept { return :: cbrt ( static_cast < double > ( _Left ) ); }
#line 672
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double fabs ( _Ty _Left ) noexcept { return :: fabs ( static_cast < double > ( _Left ) ); }
#line 673
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > hypot ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: hypot ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 675
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > pow ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: pow ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 676
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double sqrt ( _Ty _Left ) noexcept { return :: sqrt ( static_cast < double > ( _Left ) ); }
#line 677
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double erf ( _Ty _Left ) noexcept { return :: erf ( static_cast < double > ( _Left ) ); }
#line 678
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double erfc ( _Ty _Left ) noexcept { return :: erfc ( static_cast < double > ( _Left ) ); }
#line 679
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double lgamma ( _Ty _Left ) noexcept { return :: lgamma ( static_cast < double > ( _Left ) ); }
#line 680
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double tgamma ( _Ty _Left ) noexcept { return :: tgamma ( static_cast < double > ( _Left ) ); }
#line 681
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double ceil ( _Ty _Left ) noexcept { return :: ceil ( static_cast < double > ( _Left ) ); }
#line 682
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double floor ( _Ty _Left ) noexcept { return :: floor ( static_cast < double > ( _Left ) ); }
#line 683
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double nearbyint ( _Ty _Left ) noexcept { return :: nearbyint ( static_cast < double > ( _Left ) ); }
#line 684
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double rint ( _Ty _Left ) noexcept { return :: rint ( static_cast < double > ( _Left ) ); }
#line 685
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long lrint ( _Ty _Left ) noexcept { return :: lrint ( static_cast < double > ( _Left ) ); }
#line 686
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long long llrint ( _Ty _Left ) noexcept { return :: llrint ( static_cast < double > ( _Left ) ); }
#line 687
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double round ( _Ty _Left ) noexcept { return :: round ( static_cast < double > ( _Left ) ); }
#line 688
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long lround ( _Ty _Left ) noexcept { return :: lround ( static_cast < double > ( _Left ) ); }
#line 689
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] long long llround ( _Ty _Left ) noexcept { return :: llround ( static_cast < double > ( _Left ) ); }
#line 690
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double trunc ( _Ty _Left ) noexcept { return :: trunc ( static_cast < double > ( _Left ) ); }
#line 691
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmod ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmod ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 692
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > remainder ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: remainder ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 694
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > copysign ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: copysign ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 696
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > nextafter ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: nextafter ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 697
template < class _Ty, :: std :: enable_if_t < :: std :: is_integral_v < _Ty >, int > = 0 > [ [ nodiscard ] ] double nexttoward ( _Ty _Left, long double _Arg2 ) noexcept { return :: nexttoward ( static_cast < double > ( _Left ), _Arg2 ); }
#line 698
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fdim ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fdim ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 699
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmax ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmax ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 700
template < class _Ty1, class _Ty2, :: std :: enable_if_t < :: std :: is_arithmetic_v < _Ty1 > && :: std :: is_arithmetic_v < _Ty2 >, int > = 0 > [ [ nodiscard ] ] :: std :: _Common_float_type_t < _Ty1, _Ty2 > fmin ( _Ty1 _Left, _Ty2 _Right ) noexcept { return :: fmin ( static_cast < double > ( _Left ), static_cast < double > ( _Right ) ); }
#line 716
namespace std { 
#line 717
using ::abs;
#line 718
using ::acos;
#line 719
using ::asin;
#line 720
using ::atan;
#line 721
using ::atan2;
#line 722
using ::ceil;
#line 723
using ::cos;
#line 724
using ::cosh;
#line 725
using ::exp;
#line 726
using ::fabs;
#line 727
using ::floor;
#line 728
using ::fmod;
#line 729
using ::frexp;
#line 730
using ::ldexp;
#line 731
using ::log;
#line 732
using ::log10;
#line 733
using ::modf;
#line 734
using ::pow;
#line 735
using ::sin;
#line 736
using ::sinh;
#line 737
using ::sqrt;
#line 738
using ::tan;
#line 739
using ::tanh;
#line 741
using ::acosf;
#line 742
using ::asinf;
#line 743
using ::atanf;
#line 744
using ::atan2f;
#line 745
using ::ceilf;
#line 746
using ::cosf;
#line 747
using ::coshf;
#line 748
using ::expf;
#line 749
using ::fabsf;
#line 750
using ::floorf;
#line 751
using ::fmodf;
#line 752
using ::frexpf;
#line 753
using ::ldexpf;
#line 754
using ::logf;
#line 755
using ::log10f;
#line 756
using ::modff;
#line 757
using ::powf;
#line 758
using ::sinf;
#line 759
using ::sinhf;
#line 760
using ::sqrtf;
#line 761
using ::tanf;
#line 762
using ::tanhf;
#line 764
using ::acosl;
#line 765
using ::asinl;
#line 766
using ::atanl;
#line 767
using ::atan2l;
#line 768
using ::ceill;
#line 769
using ::cosl;
#line 770
using ::coshl;
#line 771
using ::expl;
#line 772
using ::fabsl;
#line 773
using ::floorl;
#line 774
using ::fmodl;
#line 775
using ::frexpl;
#line 776
using ::ldexpl;
#line 777
using ::logl;
#line 778
using ::log10l;
#line 779
using ::modfl;
#line 780
using ::powl;
#line 781
using ::sinl;
#line 782
using ::sinhl;
#line 783
using ::sqrtl;
#line 784
using ::tanl;
#line 785
using ::tanhl;
#line 787
using ::float_t;
#line 788
using ::double_t;
#line 790
using ::acosh;
#line 791
using ::asinh;
#line 792
using ::atanh;
#line 793
using ::cbrt;
#line 794
using ::erf;
#line 795
using ::erfc;
#line 796
using ::expm1;
#line 797
using ::exp2;
#line 799
inline namespace _Binary_hypot { 
#line 800
using ::hypot;
#line 801
}
#line 803
using ::ilogb;
#line 804
using ::lgamma;
#line 805
using ::log1p;
#line 806
using ::log2;
#line 807
using ::logb;
#line 808
using ::llrint;
#line 809
using ::lrint;
#line 810
using ::nearbyint;
#line 811
using ::rint;
#line 812
using ::llround;
#line 813
using ::lround;
#line 814
using ::fdim;
#line 815
using ::fma;
#line 816
using ::fmax;
#line 817
using ::fmin;
#line 818
using ::round;
#line 819
using ::trunc;
#line 820
using ::remainder;
#line 821
using ::remquo;
#line 822
using ::copysign;
#line 823
using ::nan;
#line 824
using ::nextafter;
#line 825
using ::scalbn;
#line 826
using ::scalbln;
#line 827
using ::nexttoward;
#line 828
using ::tgamma;
#line 830
using ::acoshf;
#line 831
using ::asinhf;
#line 832
using ::atanhf;
#line 833
using ::cbrtf;
#line 834
using ::erff;
#line 835
using ::erfcf;
#line 836
using ::expm1f;
#line 837
using ::exp2f;
#line 838
using ::hypotf;
#line 839
using ::ilogbf;
#line 840
using ::lgammaf;
#line 841
using ::log1pf;
#line 842
using ::log2f;
#line 843
using ::logbf;
#line 844
using ::llrintf;
#line 845
using ::lrintf;
#line 846
using ::nearbyintf;
#line 847
using ::rintf;
#line 848
using ::llroundf;
#line 849
using ::lroundf;
#line 850
using ::fdimf;
#line 851
using ::fmaf;
#line 852
using ::fmaxf;
#line 853
using ::fminf;
#line 854
using ::roundf;
#line 855
using ::truncf;
#line 856
using ::remainderf;
#line 857
using ::remquof;
#line 858
using ::copysignf;
#line 859
using ::nanf;
#line 860
using ::nextafterf;
#line 861
using ::scalbnf;
#line 862
using ::scalblnf;
#line 863
using ::nexttowardf;
#line 864
using ::tgammaf;
#line 866
using ::acoshl;
#line 867
using ::asinhl;
#line 868
using ::atanhl;
#line 869
using ::cbrtl;
#line 870
using ::erfl;
#line 871
using ::erfcl;
#line 872
using ::expm1l;
#line 873
using ::exp2l;
#line 874
using ::hypotl;
#line 875
using ::ilogbl;
#line 876
using ::lgammal;
#line 877
using ::log1pl;
#line 878
using ::log2l;
#line 879
using ::logbl;
#line 880
using ::llrintl;
#line 881
using ::lrintl;
#line 882
using ::nearbyintl;
#line 883
using ::rintl;
#line 884
using ::llroundl;
#line 885
using ::lroundl;
#line 886
using ::fdiml;
#line 887
using ::fmal;
#line 888
using ::fmaxl;
#line 889
using ::fminl;
#line 890
using ::roundl;
#line 891
using ::truncl;
#line 892
using ::remainderl;
#line 893
using ::remquol;
#line 894
using ::copysignl;
#line 895
using ::nanl;
#line 896
using ::nextafterl;
#line 897
using ::scalbnl;
#line 898
using ::scalblnl;
#line 899
using ::nexttowardl;
#line 900
using ::tgammal;
#line 902
using ::fpclassify;
#line 903
using ::signbit;
#line 904
using ::isfinite;
#line 905
using ::isinf;
#line 906
using ::isnan;
#line 907
using ::isnormal;
#line 908
using ::isgreater;
#line 909
using ::isgreaterequal;
#line 910
using ::isless;
#line 911
using ::islessequal;
#line 912
using ::islessgreater;
#line 913
using ::isunordered;
#line 914
}
#line 1489 "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\MSVC\\14.36.32532\\include\\cmath"
#pragma warning(pop)
#pragma pack ( pop )
#line 10834 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern "C" double __cdecl _hypot(double x, double y); 
#line 10835
extern "C" float __cdecl _hypotf(float x, float y); 
#line 10845 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline bool signbit(long double) throw(); 
#line 10846
extern "C" int _ldsign(long double); 
#line 10889 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline bool signbit(double) throw(); 
#line 10890
extern "C" int _dsign(double); 
#line 10934 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline bool signbit(float) throw(); 
#line 10935
extern "C" int _fdsign(float); 
#line 10943 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isinf(long double a); 
#line 10978 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isinf(double a); 
#line 11016 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isinf(float a); 
#line 11023 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isnan(long double a); 
#line 11056 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isnan(double a); 
#line 11092 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isnan(float a); 
#line 11099 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(long double a); 
#line 11136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(double a); 
#line 11172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static __inline bool isfinite(float a); 
#line 11180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
template< class T> extern T _Pow_int(T, int) throw(); 
#line 11181
extern inline __int64 abs(__int64) throw(); 
#line 11262 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline long __cdecl abs(long) throw(); 
#line 11266 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline float __cdecl abs(float) throw(); 
#line 11267
extern inline double __cdecl abs(double) throw(); 
#line 11268
extern inline float __cdecl fabs(float) throw(); 
#line 11269
extern inline float __cdecl ceil(float) throw(); 
#line 11270
extern inline float __cdecl floor(float) throw(); 
#line 11271
extern inline float __cdecl sqrt(float) throw(); 
#line 11272
extern inline float __cdecl pow(float, float) throw(); 
#line 11301 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
template< class _Ty1, class _Ty2, std::enable_if_t< std::is_arithmetic_v< _Ty1>  && std::is_arithmetic_v< _Ty2> , int>  > [[nodiscard]] std::_Common_float_type_t< _Ty1, _Ty2>  __cdecl pow(_Ty1 _Left, _Ty2 _Right) noexcept; 
#line 11308 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline float __cdecl log(float) throw(); 
#line 11309
extern inline float __cdecl log10(float) throw(); 
#line 11310
extern inline float __cdecl fmod(float, float) throw(); 
#line 11311
extern inline float __cdecl modf(float, float *) throw(); 
#line 11312
extern inline float __cdecl exp(float) throw(); 
#line 11313
extern inline float __cdecl frexp(float, int *) throw(); 
#line 11314
extern inline float __cdecl ldexp(float, int) throw(); 
#line 11315
extern inline float __cdecl asin(float) throw(); 
#line 11316
extern inline float __cdecl sin(float) throw(); 
#line 11317
extern inline float __cdecl sinh(float) throw(); 
#line 11318
extern inline float __cdecl acos(float) throw(); 
#line 11319
extern inline float __cdecl cos(float) throw(); 
#line 11320
extern inline float __cdecl cosh(float) throw(); 
#line 11321
extern inline float __cdecl atan(float) throw(); 
#line 11322
extern inline float __cdecl atan2(float, float) throw(); 
#line 11323
extern inline float __cdecl tan(float) throw(); 
#line 11324
extern inline float __cdecl tanh(float) throw(); 
#line 11547 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
extern inline float __cdecl logb(float) throw(); 
#line 11548
extern inline int __cdecl ilogb(float) throw(); 
#line 11549
extern float __cdecl scalbn(float, float) throw(); 
#line 11550
extern inline float __cdecl scalbln(float, long) throw(); 
#line 11551
extern inline float __cdecl exp2(float) throw(); 
#line 11552
extern inline float __cdecl expm1(float) throw(); 
#line 11553
extern inline float __cdecl log2(float) throw(); 
#line 11554
extern inline float __cdecl log1p(float) throw(); 
#line 11555
extern inline float __cdecl acosh(float) throw(); 
#line 11556
extern inline float __cdecl asinh(float) throw(); 
#line 11557
extern inline float __cdecl atanh(float) throw(); 
#line 11558
extern inline float __cdecl hypot(float, float) throw(); 
#line 11559
extern inline float __cdecl cbrt(float) throw(); 
#line 11560
extern inline float __cdecl erf(float) throw(); 
#line 11561
extern inline float __cdecl erfc(float) throw(); 
#line 11562
extern inline float __cdecl lgamma(float) throw(); 
#line 11563
extern inline float __cdecl tgamma(float) throw(); 
#line 11564
extern inline float __cdecl copysign(float, float) throw(); 
#line 11565
extern inline float __cdecl nextafter(float, float) throw(); 
#line 11566
extern inline float __cdecl remainder(float, float) throw(); 
#line 11567
extern inline float __cdecl remquo(float, float, int *) throw(); 
#line 11568
extern inline float __cdecl round(float) throw(); 
#line 11569
extern inline long __cdecl lround(float) throw(); 
#line 11570
extern inline __int64 __cdecl llround(float) throw(); 
#line 11571
extern inline float __cdecl trunc(float) throw(); 
#line 11572
extern inline float __cdecl rint(float) throw(); 
#line 11573
extern inline long __cdecl lrint(float) throw(); 
#line 11574
extern inline __int64 __cdecl llrint(float) throw(); 
#line 11575
extern inline float __cdecl nearbyint(float) throw(); 
#line 11576
extern inline float __cdecl fdim(float, float) throw(); 
#line 11577
extern inline float __cdecl fma(float, float, float) throw(); 
#line 11578
extern inline float __cdecl fmax(float, float) throw(); 
#line 11579
extern inline float __cdecl fmin(float, float) throw(); 
#line 11582 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
static inline float exp10(const float a); 
#line 11584
static inline float rsqrt(const float a); 
#line 11586
static inline float rcbrt(const float a); 
#line 11588
static inline float sinpi(const float a); 
#line 11590
static inline float cospi(const float a); 
#line 11592
static inline void sincospi(const float a, float *const sptr, float *const cptr); 
#line 11594
static inline void sincos(const float a, float *const sptr, float *const cptr); 
#line 11596
static inline float j0(const float a); 
#line 11598
static inline float j1(const float a); 
#line 11600
static inline float jn(const int n, const float a); 
#line 11602
static inline float y0(const float a); 
#line 11604
static inline float y1(const float a); 
#line 11606
static inline float yn(const int n, const float a); 
#line 11608
static inline float cyl_bessel_i0(const float a); 
#line 11610
static inline float cyl_bessel_i1(const float a); 
#line 11612
static inline float erfinv(const float a); 
#line 11614
static inline float erfcinv(const float a); 
#line 11616
static inline float normcdfinv(const float a); 
#line 11618
static inline float normcdf(const float a); 
#line 11620
static inline float erfcx(const float a); 
#line 11622
static inline double copysign(const double a, const float b); 
#line 11624
static inline double copysign(const float a, const double b); 
#line 11632
static inline unsigned min(const unsigned a, const unsigned b); 
#line 11640
static inline unsigned min(const int a, const unsigned b); 
#line 11648
static inline unsigned min(const unsigned a, const int b); 
#line 11656
static inline long min(const long a, const long b); 
#line 11664
static inline unsigned long min(const unsigned long a, const unsigned long b); 
#line 11672
static inline unsigned long min(const long a, const unsigned long b); 
#line 11680
static inline unsigned long min(const unsigned long a, const long b); 
#line 11688
static inline __int64 min(const __int64 a, const __int64 b); 
#line 11696
static inline unsigned __int64 min(const unsigned __int64 a, const unsigned __int64 b); 
#line 11704
static inline unsigned __int64 min(const __int64 a, const unsigned __int64 b); 
#line 11712
static inline unsigned __int64 min(const unsigned __int64 a, const __int64 b); 
#line 11723
static inline float min(const float a, const float b); 
#line 11734
static inline double min(const double a, const double b); 
#line 11744
static inline double min(const float a, const double b); 
#line 11754
static inline double min(const double a, const float b); 
#line 11762
static inline unsigned max(const unsigned a, const unsigned b); 
#line 11770
static inline unsigned max(const int a, const unsigned b); 
#line 11778
static inline unsigned max(const unsigned a, const int b); 
#line 11786
static inline long max(const long a, const long b); 
#line 11794
static inline unsigned long max(const unsigned long a, const unsigned long b); 
#line 11802
static inline unsigned long max(const long a, const unsigned long b); 
#line 11810
static inline unsigned long max(const unsigned long a, const long b); 
#line 11818
static inline __int64 max(const __int64 a, const __int64 b); 
#line 11826
static inline unsigned __int64 max(const unsigned __int64 a, const unsigned __int64 b); 
#line 11834
static inline unsigned __int64 max(const __int64 a, const unsigned __int64 b); 
#line 11842
static inline unsigned __int64 max(const unsigned __int64 a, const __int64 b); 
#line 11853
static inline float max(const float a, const float b); 
#line 11864
static inline double max(const double a, const double b); 
#line 11874
static inline double max(const float a, const double b); 
#line 11884
static inline double max(const double a, const float b); 
#line 11895
extern "C" {
#line 11896
inline void *__nv_aligned_device_malloc(size_t size, size_t align) {int volatile ___ = 1;(void)size;(void)align;::exit(___);}
#if 0
#line 11897
{ 
#line 11898
void *__nv_aligned_device_malloc_impl(size_t, size_t); 
#line 11899
return __nv_aligned_device_malloc_impl(size, align); 
#line 11900
} 
#endif
#line 11901 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.h"
}
#line 433 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const long double a) 
#line 434
{ 
#line 438 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isinf< long double> (a); 
#line 440 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 449 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const double a) 
#line 450
{ 
#line 454 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isinf< double> (a); 
#line 456 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 465 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isinf(const float a) 
#line 466
{ 
#line 470 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isinf< float> (a); 
#line 472 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 481 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const long double a) 
#line 482
{ 
#line 486 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isnan< long double> (a); 
#line 488 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 497 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const double a) 
#line 498
{ 
#line 502 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isnan< double> (a); 
#line 504 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 513 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isnan(const float a) 
#line 514
{ 
#line 518 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isnan< float> (a); 
#line 520 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 529 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const long double a) 
#line 530
{ 
#line 534 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isfinite< long double> (a); 
#line 536 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const double a) 
#line 546
{ 
#line 550 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isfinite< double> (a); 
#line 552 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 561 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static __inline bool isfinite(const float a) 
#line 562
{ 
#line 566 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
return isfinite< float> (a); 
#line 568 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
} 
#line 758 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static inline float exp10(const float a) 
#line 759
{ 
#line 760
return exp10f(a); 
#line 761
} 
#line 763
static inline float rsqrt(const float a) 
#line 764
{ 
#line 765
return rsqrtf(a); 
#line 766
} 
#line 768
static inline float rcbrt(const float a) 
#line 769
{ 
#line 770
return rcbrtf(a); 
#line 771
} 
#line 773
static inline float sinpi(const float a) 
#line 774
{ 
#line 775
return sinpif(a); 
#line 776
} 
#line 778
static inline float cospi(const float a) 
#line 779
{ 
#line 780
return cospif(a); 
#line 781
} 
#line 783
static inline void sincospi(const float a, float *const sptr, float *const cptr) 
#line 784
{ 
#line 785
sincospif(a, sptr, cptr); 
#line 786
} 
#line 788
static inline void sincos(const float a, float *const sptr, float *const cptr) 
#line 789
{ 
#line 790
sincosf(a, sptr, cptr); 
#line 791
} 
#line 793
static inline float j0(const float a) 
#line 794
{ 
#line 795
return j0f(a); 
#line 796
} 
#line 798
static inline float j1(const float a) 
#line 799
{ 
#line 800
return j1f(a); 
#line 801
} 
#line 803
static inline float jn(const int n, const float a) 
#line 804
{ 
#line 805
return jnf(n, a); 
#line 806
} 
#line 808
static inline float y0(const float a) 
#line 809
{ 
#line 810
return y0f(a); 
#line 811
} 
#line 813
static inline float y1(const float a) 
#line 814
{ 
#line 815
return y1f(a); 
#line 816
} 
#line 818
static inline float yn(const int n, const float a) 
#line 819
{ 
#line 820
return ynf(n, a); 
#line 821
} 
#line 823
static inline float cyl_bessel_i0(const float a) {int volatile ___ = 1;(void)a;::exit(___);}
#if 0
#line 824
{ 
#line 825
return cyl_bessel_i0f(a); 
#line 826
} 
#endif
#line 828 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static inline float cyl_bessel_i1(const float a) {int volatile ___ = 1;(void)a;::exit(___);}
#if 0
#line 829
{ 
#line 830
return cyl_bessel_i1f(a); 
#line 831
} 
#endif
#line 833 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static inline float erfinv(const float a) 
#line 834
{ 
#line 835
return erfinvf(a); 
#line 836
} 
#line 838
static inline float erfcinv(const float a) 
#line 839
{ 
#line 840
return erfcinvf(a); 
#line 841
} 
#line 843
static inline float normcdfinv(const float a) 
#line 844
{ 
#line 845
return normcdfinvf(a); 
#line 846
} 
#line 848
static inline float normcdf(const float a) 
#line 849
{ 
#line 850
return normcdff(a); 
#line 851
} 
#line 853
static inline float erfcx(const float a) 
#line 854
{ 
#line 855
return erfcxf(a); 
#line 856
} 
#line 858
static inline double copysign(const double a, const float b) 
#line 859
{ 
#line 860
return copysign(a, static_cast< double>(b)); 
#line 861
} 
#line 863
static inline double copysign(const float a, const double b) 
#line 864
{ 
#line 865
return copysign(static_cast< double>(a), b); 
#line 866
} 
#line 868
static inline unsigned min(const unsigned a, const unsigned b) 
#line 869
{ 
#line 870
return umin(a, b); 
#line 871
} 
#line 873
static inline unsigned min(const int a, const unsigned b) 
#line 874
{ 
#line 875
return umin(static_cast< unsigned>(a), b); 
#line 876
} 
#line 878
static inline unsigned min(const unsigned a, const int b) 
#line 879
{ 
#line 880
return umin(a, static_cast< unsigned>(b)); 
#line 881
} 
#line 883
static inline long min(const long a, const long b) 
#line 884
{ 
#line 885
long retval; 
#line 888
#pragma warning (disable: 4127)
#line 891 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(long) == sizeof(int)) { 
#line 893
#pragma warning (default: 4127)
#line 895 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< long>(min(static_cast< int>(a), static_cast< int>(b)))); 
#line 896
} else { 
#line 897
retval = (static_cast< long>(llmin(static_cast< __int64>(a), static_cast< __int64>(b)))); 
#line 898
}  
#line 899
return retval; 
#line 900
} 
#line 902
static inline unsigned long min(const unsigned long a, const unsigned long b) 
#line 903
{ 
#line 904
unsigned long retval; 
#line 906
#pragma warning (disable: 4127)
#line 908 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 910
#pragma warning (default: 4127)
#line 912 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 913
} else { 
#line 914
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 915
}  
#line 916
return retval; 
#line 917
} 
#line 919
static inline unsigned long min(const long a, const unsigned long b) 
#line 920
{ 
#line 921
unsigned long retval; 
#line 923
#pragma warning (disable: 4127)
#line 925 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 927
#pragma warning (default: 4127)
#line 929 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 930
} else { 
#line 931
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 932
}  
#line 933
return retval; 
#line 934
} 
#line 936
static inline unsigned long min(const unsigned long a, const long b) 
#line 937
{ 
#line 938
unsigned long retval; 
#line 940
#pragma warning (disable: 4127)
#line 942 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 944
#pragma warning (default: 4127)
#line 946 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umin(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 947
} else { 
#line 948
retval = (static_cast< unsigned long>(ullmin(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 949
}  
#line 950
return retval; 
#line 951
} 
#line 953
static inline __int64 min(const __int64 a, const __int64 b) 
#line 954
{ 
#line 955
return llmin(a, b); 
#line 956
} 
#line 958
static inline unsigned __int64 min(const unsigned __int64 a, const unsigned __int64 b) 
#line 959
{ 
#line 960
return ullmin(a, b); 
#line 961
} 
#line 963
static inline unsigned __int64 min(const __int64 a, const unsigned __int64 b) 
#line 964
{ 
#line 965
return ullmin(static_cast< unsigned __int64>(a), b); 
#line 966
} 
#line 968
static inline unsigned __int64 min(const unsigned __int64 a, const __int64 b) 
#line 969
{ 
#line 970
return ullmin(a, static_cast< unsigned __int64>(b)); 
#line 971
} 
#line 973
static inline float min(const float a, const float b) 
#line 974
{ 
#line 975
return fminf(a, b); 
#line 976
} 
#line 978
static inline double min(const double a, const double b) 
#line 979
{ 
#line 980
return fmin(a, b); 
#line 981
} 
#line 983
static inline double min(const float a, const double b) 
#line 984
{ 
#line 985
return fmin(static_cast< double>(a), b); 
#line 986
} 
#line 988
static inline double min(const double a, const float b) 
#line 989
{ 
#line 990
return fmin(a, static_cast< double>(b)); 
#line 991
} 
#line 993
static inline unsigned max(const unsigned a, const unsigned b) 
#line 994
{ 
#line 995
return umax(a, b); 
#line 996
} 
#line 998
static inline unsigned max(const int a, const unsigned b) 
#line 999
{ 
#line 1000
return umax(static_cast< unsigned>(a), b); 
#line 1001
} 
#line 1003
static inline unsigned max(const unsigned a, const int b) 
#line 1004
{ 
#line 1005
return umax(a, static_cast< unsigned>(b)); 
#line 1006
} 
#line 1008
static inline long max(const long a, const long b) 
#line 1009
{ 
#line 1010
long retval; 
#line 1013
#pragma warning (disable: 4127)
#line 1015 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(long) == sizeof(int)) { 
#line 1017
#pragma warning (default: 4127)
#line 1019 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< long>(max(static_cast< int>(a), static_cast< int>(b)))); 
#line 1020
} else { 
#line 1021
retval = (static_cast< long>(llmax(static_cast< __int64>(a), static_cast< __int64>(b)))); 
#line 1022
}  
#line 1023
return retval; 
#line 1024
} 
#line 1026
static inline unsigned long max(const unsigned long a, const unsigned long b) 
#line 1027
{ 
#line 1028
unsigned long retval; 
#line 1030
#pragma warning (disable: 4127)
#line 1032 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1034
#pragma warning (default: 4127)
#line 1036 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1037
} else { 
#line 1038
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1039
}  
#line 1040
return retval; 
#line 1041
} 
#line 1043
static inline unsigned long max(const long a, const unsigned long b) 
#line 1044
{ 
#line 1045
unsigned long retval; 
#line 1047
#pragma warning (disable: 4127)
#line 1049 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1051
#pragma warning (default: 4127)
#line 1053 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1054
} else { 
#line 1055
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1056
}  
#line 1057
return retval; 
#line 1058
} 
#line 1060
static inline unsigned long max(const unsigned long a, const long b) 
#line 1061
{ 
#line 1062
unsigned long retval; 
#line 1064
#pragma warning (disable: 4127)
#line 1066 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
if (sizeof(unsigned long) == sizeof(unsigned)) { 
#line 1068
#pragma warning (default: 4127)
#line 1070 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
retval = (static_cast< unsigned long>(umax(static_cast< unsigned>(a), static_cast< unsigned>(b)))); 
#line 1071
} else { 
#line 1072
retval = (static_cast< unsigned long>(ullmax(static_cast< unsigned __int64>(a), static_cast< unsigned __int64>(b)))); 
#line 1073
}  
#line 1074
return retval; 
#line 1075
} 
#line 1077
static inline __int64 max(const __int64 a, const __int64 b) 
#line 1078
{ 
#line 1079
return llmax(a, b); 
#line 1080
} 
#line 1082
static inline unsigned __int64 max(const unsigned __int64 a, const unsigned __int64 b) 
#line 1083
{ 
#line 1084
return ullmax(a, b); 
#line 1085
} 
#line 1087
static inline unsigned __int64 max(const __int64 a, const unsigned __int64 b) 
#line 1088
{ 
#line 1089
return ullmax(static_cast< unsigned __int64>(a), b); 
#line 1090
} 
#line 1092
static inline unsigned __int64 max(const unsigned __int64 a, const __int64 b) 
#line 1093
{ 
#line 1094
return ullmax(a, static_cast< unsigned __int64>(b)); 
#line 1095
} 
#line 1097
static inline float max(const float a, const float b) 
#line 1098
{ 
#line 1099
return fmaxf(a, b); 
#line 1100
} 
#line 1102
static inline double max(const double a, const double b) 
#line 1103
{ 
#line 1104
return fmax(a, b); 
#line 1105
} 
#line 1107
static inline double max(const float a, const double b) 
#line 1108
{ 
#line 1109
return fmax(static_cast< double>(a), b); 
#line 1110
} 
#line 1112
static inline double max(const double a, const float b) 
#line 1113
{ 
#line 1114
return fmax(a, static_cast< double>(b)); 
#line 1115
} 
#line 1121
#pragma warning(disable : 4211)
#line 1126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\math_functions.hpp"
static inline int min(const int a, const int b) 
#line 1127
{ 
#line 1128
return (a < b) ? a : b; 
#line 1129
} 
#line 1131
static inline unsigned umin(const unsigned a, const unsigned b) 
#line 1132
{ 
#line 1133
return (a < b) ? a : b; 
#line 1134
} 
#line 1136
static inline __int64 llmin(const __int64 a, const __int64 b) 
#line 1137
{ 
#line 1138
return (a < b) ? a : b; 
#line 1139
} 
#line 1141
static inline unsigned __int64 ullmin(const unsigned __int64 a, const unsigned __int64 
#line 1142
b) 
#line 1143
{ 
#line 1144
return (a < b) ? a : b; 
#line 1145
} 
#line 1147
static inline int max(const int a, const int b) 
#line 1148
{ 
#line 1149
return (a > b) ? a : b; 
#line 1150
} 
#line 1152
static inline unsigned umax(const unsigned a, const unsigned b) 
#line 1153
{ 
#line 1154
return (a > b) ? a : b; 
#line 1155
} 
#line 1157
static inline __int64 llmax(const __int64 a, const __int64 b) 
#line 1158
{ 
#line 1159
return (a > b) ? a : b; 
#line 1160
} 
#line 1162
static inline unsigned __int64 ullmax(const unsigned __int64 a, const unsigned __int64 
#line 1163
b) 
#line 1164
{ 
#line 1165
return (a > b) ? a : b; 
#line 1166
} 
#line 1169
#pragma warning(default: 4211)
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/device_functions.h"
extern "C" {
#line 3211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/device_functions.h"
static __inline int __vimax_s32_relu(const int a, const int b); 
#line 3223
static __inline unsigned __vimax_s16x2_relu(const unsigned a, const unsigned b); 
#line 3232
static __inline int __vimin_s32_relu(const int a, const int b); 
#line 3244
static __inline unsigned __vimin_s16x2_relu(const unsigned a, const unsigned b); 
#line 3253
static __inline int __vimax3_s32(const int a, const int b, const int c); 
#line 3265
static __inline unsigned __vimax3_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3274
static __inline unsigned __vimax3_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 3286
static __inline unsigned __vimax3_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3295
static __inline int __vimin3_s32(const int a, const int b, const int c); 
#line 3307
static __inline unsigned __vimin3_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3316
static __inline unsigned __vimin3_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 3328
static __inline unsigned __vimin3_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3337
static __inline int __vimax3_s32_relu(const int a, const int b, const int c); 
#line 3349
static __inline unsigned __vimax3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 3358
static __inline int __vimin3_s32_relu(const int a, const int b, const int c); 
#line 3370
static __inline unsigned __vimin3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 3379
static __inline int __viaddmax_s32(const int a, const int b, const int c); 
#line 3391
static __inline unsigned __viaddmax_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3400
static __inline unsigned __viaddmax_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 3412
static __inline unsigned __viaddmax_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3421
static __inline int __viaddmin_s32(const int a, const int b, const int c); 
#line 3433
static __inline unsigned __viaddmin_s16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3442
static __inline unsigned __viaddmin_u32(const unsigned a, const unsigned b, const unsigned c); 
#line 3454
static __inline unsigned __viaddmin_u16x2(const unsigned a, const unsigned b, const unsigned c); 
#line 3464
static __inline int __viaddmax_s32_relu(const int a, const int b, const int c); 
#line 3476
static __inline unsigned __viaddmax_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 3486
static __inline int __viaddmin_s32_relu(const int a, const int b, const int c); 
#line 3498
static __inline unsigned __viaddmin_s16x2_relu(const unsigned a, const unsigned b, const unsigned c); 
#line 3507
static __inline int __vibmax_s32(const int a, const int b, bool *const pred); 
#line 3516
static __inline unsigned __vibmax_u32(const unsigned a, const unsigned b, bool *const pred); 
#line 3525
static __inline int __vibmin_s32(const int a, const int b, bool *const pred); 
#line 3534
static __inline unsigned __vibmin_u32(const unsigned a, const unsigned b, bool *const pred); 
#line 3548
static __inline unsigned __vibmax_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 3562
static __inline unsigned __vibmax_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 3576
static __inline unsigned __vibmin_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 3590
static __inline unsigned __vibmin_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo); 
#line 3597
}
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
static __inline int __vimax_s32_relu(const int a, const int b) { 
#line 109
int ans = max(a, b); 
#line 111
return (ans > 0) ? ans : 0; 
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 115
static __inline unsigned __vimax_s16x2_relu(const unsigned a, const unsigned b) { 
#line 123
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 124
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 126
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 127
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 130
short aS_lo = *((short *)(&aU_lo)); 
#line 131
short aS_hi = *((short *)(&aU_hi)); 
#line 133
short bS_lo = *((short *)(&bU_lo)); 
#line 134
short bS_hi = *((short *)(&bU_hi)); 
#line 137
short ansS_lo = (short)max(aS_lo, bS_lo); 
#line 138
short ansS_hi = (short)max(aS_hi, bS_hi); 
#line 141
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 142
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 145
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 146
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 149
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 151
return ans; 
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 155
static __inline int __vimin_s32_relu(const int a, const int b) { 
#line 162
int ans = min(a, b); 
#line 164
return (ans > 0) ? ans : 0; 
#line 166 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 168
static __inline unsigned __vimin_s16x2_relu(const unsigned a, const unsigned b) { 
#line 176
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 177
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 179
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 180
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 183
short aS_lo = *((short *)(&aU_lo)); 
#line 184
short aS_hi = *((short *)(&aU_hi)); 
#line 186
short bS_lo = *((short *)(&bU_lo)); 
#line 187
short bS_hi = *((short *)(&bU_hi)); 
#line 190
short ansS_lo = (short)min(aS_lo, bS_lo); 
#line 191
short ansS_hi = (short)min(aS_hi, bS_hi); 
#line 194
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 195
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 198
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 199
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 202
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 204
return ans; 
#line 206 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 208
static __inline int __vimax3_s32(const int a, const int b, const int c) { 
#line 218
return max(max(a, b), c); 
#line 220 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 222
static __inline unsigned __vimax3_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 234
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 235
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 237
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 238
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 240
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 241
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 244
short aS_lo = *((short *)(&aU_lo)); 
#line 245
short aS_hi = *((short *)(&aU_hi)); 
#line 247
short bS_lo = *((short *)(&bU_lo)); 
#line 248
short bS_hi = *((short *)(&bU_hi)); 
#line 250
short cS_lo = *((short *)(&cU_lo)); 
#line 251
short cS_hi = *((short *)(&cU_hi)); 
#line 254
short ansS_lo = (short)max(max(aS_lo, bS_lo), cS_lo); 
#line 255
short ansS_hi = (short)max(max(aS_hi, bS_hi), cS_hi); 
#line 258
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 259
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 262
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 264
return ans; 
#line 266 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 268
static __inline unsigned __vimax3_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 278
return max(max(a, b), c); 
#line 280 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 282
static __inline unsigned __vimax3_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 293
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 294
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 296
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 297
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 299
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 300
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 303
unsigned short ansU_lo = (unsigned short)max(max(aU_lo, bU_lo), cU_lo); 
#line 304
unsigned short ansU_hi = (unsigned short)max(max(aU_hi, bU_hi), cU_hi); 
#line 307
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 309
return ans; 
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 313
static __inline int __vimin3_s32(const int a, const int b, const int c) { 
#line 323
return min(min(a, b), c); 
#line 325 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 327
static __inline unsigned __vimin3_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 338
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 339
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 341
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 342
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 344
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 345
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 348
short aS_lo = *((short *)(&aU_lo)); 
#line 349
short aS_hi = *((short *)(&aU_hi)); 
#line 351
short bS_lo = *((short *)(&bU_lo)); 
#line 352
short bS_hi = *((short *)(&bU_hi)); 
#line 354
short cS_lo = *((short *)(&cU_lo)); 
#line 355
short cS_hi = *((short *)(&cU_hi)); 
#line 358
short ansS_lo = (short)min(min(aS_lo, bS_lo), cS_lo); 
#line 359
short ansS_hi = (short)min(min(aS_hi, bS_hi), cS_hi); 
#line 362
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 363
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 366
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 368
return ans; 
#line 370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 372
static __inline unsigned __vimin3_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 382
return min(min(a, b), c); 
#line 384 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 386
static __inline unsigned __vimin3_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 397
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 398
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 400
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 401
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 403
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 404
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 407
unsigned short ansU_lo = (unsigned short)min(min(aU_lo, bU_lo), cU_lo); 
#line 408
unsigned short ansU_hi = (unsigned short)min(min(aU_hi, bU_hi), cU_hi); 
#line 411
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 413
return ans; 
#line 415 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 417
static __inline int __vimax3_s32_relu(const int a, const int b, const int c) { 
#line 427
int ans = max(max(a, b), c); 
#line 429
return (ans > 0) ? ans : 0; 
#line 431 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 433
static __inline unsigned __vimax3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 444
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 445
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 447
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 448
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 450
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 451
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 454
short aS_lo = *((short *)(&aU_lo)); 
#line 455
short aS_hi = *((short *)(&aU_hi)); 
#line 457
short bS_lo = *((short *)(&bU_lo)); 
#line 458
short bS_hi = *((short *)(&bU_hi)); 
#line 460
short cS_lo = *((short *)(&cU_lo)); 
#line 461
short cS_hi = *((short *)(&cU_hi)); 
#line 464
short ansS_lo = (short)max(max(aS_lo, bS_lo), cS_lo); 
#line 465
short ansS_hi = (short)max(max(aS_hi, bS_hi), cS_hi); 
#line 468
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 469
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 472
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 473
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 476
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 478
return ans; 
#line 480 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 482
static __inline int __vimin3_s32_relu(const int a, const int b, const int c) { 
#line 492
int ans = min(min(a, b), c); 
#line 494
return (ans > 0) ? ans : 0; 
#line 496 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 498
static __inline unsigned __vimin3_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 509
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 510
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 512
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 513
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 515
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 516
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 519
short aS_lo = *((short *)(&aU_lo)); 
#line 520
short aS_hi = *((short *)(&aU_hi)); 
#line 522
short bS_lo = *((short *)(&bU_lo)); 
#line 523
short bS_hi = *((short *)(&bU_hi)); 
#line 525
short cS_lo = *((short *)(&cU_lo)); 
#line 526
short cS_hi = *((short *)(&cU_hi)); 
#line 529
short ansS_lo = (short)min(min(aS_lo, bS_lo), cS_lo); 
#line 530
short ansS_hi = (short)min(min(aS_hi, bS_hi), cS_hi); 
#line 533
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 534
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 537
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 538
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 541
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 543
return ans; 
#line 545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 547
static __inline int __viaddmax_s32(const int a, const int b, const int c) { 
#line 557
return max(a + b, c); 
#line 559 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 561
static __inline unsigned __viaddmax_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 572
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 573
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 575
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 576
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 578
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 579
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 582
short aS_lo = *((short *)(&aU_lo)); 
#line 583
short aS_hi = *((short *)(&aU_hi)); 
#line 585
short bS_lo = *((short *)(&bU_lo)); 
#line 586
short bS_hi = *((short *)(&bU_hi)); 
#line 588
short cS_lo = *((short *)(&cU_lo)); 
#line 589
short cS_hi = *((short *)(&cU_hi)); 
#line 592
short ansS_lo = (short)max((short)(aS_lo + bS_lo), cS_lo); 
#line 593
short ansS_hi = (short)max((short)(aS_hi + bS_hi), cS_hi); 
#line 596
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 597
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 600
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 602
return ans; 
#line 604 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 606
static __inline unsigned __viaddmax_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 616
return max(a + b, c); 
#line 618 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 620
static __inline unsigned __viaddmax_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 631
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 632
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 634
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 635
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 637
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 638
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 641
unsigned short ansU_lo = (unsigned short)max((unsigned short)(aU_lo + bU_lo), cU_lo); 
#line 642
unsigned short ansU_hi = (unsigned short)max((unsigned short)(aU_hi + bU_hi), cU_hi); 
#line 645
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 647
return ans; 
#line 649 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 651
static __inline int __viaddmin_s32(const int a, const int b, const int c) { 
#line 661
return min(a + b, c); 
#line 663 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 665
static __inline unsigned __viaddmin_s16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 676
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 677
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 679
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 680
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 682
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 683
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 686
short aS_lo = *((short *)(&aU_lo)); 
#line 687
short aS_hi = *((short *)(&aU_hi)); 
#line 689
short bS_lo = *((short *)(&bU_lo)); 
#line 690
short bS_hi = *((short *)(&bU_hi)); 
#line 692
short cS_lo = *((short *)(&cU_lo)); 
#line 693
short cS_hi = *((short *)(&cU_hi)); 
#line 696
short ansS_lo = (short)min((short)(aS_lo + bS_lo), cS_lo); 
#line 697
short ansS_hi = (short)min((short)(aS_hi + bS_hi), cS_hi); 
#line 700
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 701
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 704
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 706
return ans; 
#line 708 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 710
static __inline unsigned __viaddmin_u32(const unsigned a, const unsigned b, const unsigned c) { 
#line 720
return min(a + b, c); 
#line 722 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 724
static __inline unsigned __viaddmin_u16x2(const unsigned a, const unsigned b, const unsigned c) { 
#line 735
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 736
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 738
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 739
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 741
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 742
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 745
unsigned short ansU_lo = (unsigned short)min((unsigned short)(aU_lo + bU_lo), cU_lo); 
#line 746
unsigned short ansU_hi = (unsigned short)min((unsigned short)(aU_hi + bU_hi), cU_hi); 
#line 749
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 751
return ans; 
#line 753 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 755
static __inline int __viaddmax_s32_relu(const int a, const int b, const int c) { 
#line 765
int ans = max(a + b, c); 
#line 767
return (ans > 0) ? ans : 0; 
#line 769 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 771
static __inline unsigned __viaddmax_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 782
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 783
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 785
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 786
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 788
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 789
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 792
short aS_lo = *((short *)(&aU_lo)); 
#line 793
short aS_hi = *((short *)(&aU_hi)); 
#line 795
short bS_lo = *((short *)(&bU_lo)); 
#line 796
short bS_hi = *((short *)(&bU_hi)); 
#line 798
short cS_lo = *((short *)(&cU_lo)); 
#line 799
short cS_hi = *((short *)(&cU_hi)); 
#line 802
short ansS_lo = (short)max((short)(aS_lo + bS_lo), cS_lo); 
#line 803
short ansS_hi = (short)max((short)(aS_hi + bS_hi), cS_hi); 
#line 805
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 806
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 809
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 810
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 813
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 815
return ans; 
#line 817 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 819
static __inline int __viaddmin_s32_relu(const int a, const int b, const int c) { 
#line 829
int ans = min(a + b, c); 
#line 831
return (ans > 0) ? ans : 0; 
#line 833 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 835
static __inline unsigned __viaddmin_s16x2_relu(const unsigned a, const unsigned b, const unsigned c) { 
#line 846
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 847
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 849
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 850
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 852
unsigned short cU_lo = (unsigned short)(c & 65535U); 
#line 853
unsigned short cU_hi = (unsigned short)(c >> 16); 
#line 856
short aS_lo = *((short *)(&aU_lo)); 
#line 857
short aS_hi = *((short *)(&aU_hi)); 
#line 859
short bS_lo = *((short *)(&bU_lo)); 
#line 860
short bS_hi = *((short *)(&bU_hi)); 
#line 862
short cS_lo = *((short *)(&cU_lo)); 
#line 863
short cS_hi = *((short *)(&cU_hi)); 
#line 866
short ansS_lo = (short)min((short)(aS_lo + bS_lo), cS_lo); 
#line 867
short ansS_hi = (short)min((short)(aS_hi + bS_hi), cS_hi); 
#line 869
if (ansS_lo < 0) { ansS_lo = (0); }  
#line 870
if (ansS_hi < 0) { ansS_hi = (0); }  
#line 873
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 874
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 877
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 879
return ans; 
#line 881 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 885
static __inline int __vibmax_s32(const int a, const int b, bool *const pred) { 
#line 899
int ans = max(a, b); 
#line 901
(*pred) = (a >= b); 
#line 902
return ans; 
#line 904 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 906
static __inline unsigned __vibmax_u32(const unsigned a, const unsigned b, bool *const pred) { 
#line 920
unsigned ans = max(a, b); 
#line 922
(*pred) = (a >= b); 
#line 923
return ans; 
#line 925 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 928
static __inline int __vibmin_s32(const int a, const int b, bool *const pred) { 
#line 942
int ans = min(a, b); 
#line 944
(*pred) = (a <= b); 
#line 945
return ans; 
#line 947 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 950
static __inline unsigned __vibmin_u32(const unsigned a, const unsigned b, bool *const pred) { 
#line 964
unsigned ans = min(a, b); 
#line 966
(*pred) = (a <= b); 
#line 967
return ans; 
#line 969 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 971
static __inline unsigned __vibmax_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 993
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 994
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 996
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 997
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1000
short aS_lo = *((short *)(&aU_lo)); 
#line 1001
short aS_hi = *((short *)(&aU_hi)); 
#line 1003
short bS_lo = *((short *)(&bU_lo)); 
#line 1004
short bS_hi = *((short *)(&bU_hi)); 
#line 1007
short ansS_lo = (short)max(aS_lo, bS_lo); 
#line 1008
short ansS_hi = (short)max(aS_hi, bS_hi); 
#line 1010
(*pred_hi) = (aS_hi >= bS_hi); 
#line 1011
(*pred_lo) = (aS_lo >= bS_lo); 
#line 1014
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 1015
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 1018
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1020
return ans; 
#line 1022 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 1024
static __inline unsigned __vibmax_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1046
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1047
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1049
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1050
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1053
unsigned short ansU_lo = (unsigned short)max(aU_lo, bU_lo); 
#line 1054
unsigned short ansU_hi = (unsigned short)max(aU_hi, bU_hi); 
#line 1056
(*pred_hi) = (aU_hi >= bU_hi); 
#line 1057
(*pred_lo) = (aU_lo >= bU_lo); 
#line 1060
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1062
return ans; 
#line 1064 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 1066
static __inline unsigned __vibmin_s16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1088
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1089
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1091
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1092
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1095
short aS_lo = *((short *)(&aU_lo)); 
#line 1096
short aS_hi = *((short *)(&aU_hi)); 
#line 1098
short bS_lo = *((short *)(&bU_lo)); 
#line 1099
short bS_hi = *((short *)(&bU_hi)); 
#line 1102
short ansS_lo = (short)min(aS_lo, bS_lo); 
#line 1103
short ansS_hi = (short)min(aS_hi, bS_hi); 
#line 1105
(*pred_hi) = (aS_hi <= bS_hi); 
#line 1106
(*pred_lo) = (aS_lo <= bS_lo); 
#line 1109
unsigned short ansU_lo = *((unsigned short *)(&ansS_lo)); 
#line 1110
unsigned short ansU_hi = *((unsigned short *)(&ansS_hi)); 
#line 1113
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1115
return ans; 
#line 1117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 1119
static __inline unsigned __vibmin_u16x2(const unsigned a, const unsigned b, bool *const pred_hi, bool *const pred_lo) { 
#line 1141
unsigned short aU_lo = (unsigned short)(a & 65535U); 
#line 1142
unsigned short aU_hi = (unsigned short)(a >> 16); 
#line 1144
unsigned short bU_lo = (unsigned short)(b & 65535U); 
#line 1145
unsigned short bU_hi = (unsigned short)(b >> 16); 
#line 1148
unsigned short ansU_lo = (unsigned short)min(aU_lo, bU_lo); 
#line 1149
unsigned short ansU_hi = (unsigned short)min(aU_hi, bU_hi); 
#line 1151
(*pred_hi) = (aU_hi <= bU_hi); 
#line 1152
(*pred_lo) = (aU_lo <= bU_lo); 
#line 1155
unsigned ans = ((unsigned)ansU_lo) | (((unsigned)ansU_hi) << 16); 
#line 1157
return ans; 
#line 1159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_functions.hpp"
} 
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicAdd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicAdd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicSub(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicSub(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicExch(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 118
{ } 
#endif
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicExch(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 120
{ } 
#endif
#line 122 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline float atomicExch(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 122
{ } 
#endif
#line 124 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicMin(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 124
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicMin(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicMax(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 130 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicMax(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 130
{ } 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicInc(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 132
{ } 
#endif
#line 134 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicDec(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 134
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicAnd(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicAnd(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 138
{ } 
#endif
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicOr(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 140
{ } 
#endif
#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicOr(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 142
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicXor(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicXor(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 146
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline int atomicCAS(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 150 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned atomicCAS(unsigned *address, unsigned compare, unsigned val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 150
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
extern "C" {
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
}
#line 195
static __inline unsigned __int64 atomicAdd(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 195
{ } 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned __int64 atomicExch(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 197
{ } 
#endif
#line 199 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
static __inline unsigned __int64 atomicCAS(unsigned __int64 *address, unsigned __int64 compare, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 199
{ } 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
__declspec(deprecated("__any() is deprecated in favor of __any_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning).")) static __inline bool any(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
#line 201
{ } 
#endif
#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_atomic_functions.h"
__declspec(deprecated("__all() is deprecated in favor of __all_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to suppr" "ess this warning).")) static __inline bool all(bool cond) {int volatile ___ = 1;(void)cond;::exit(___);}
#if 0
#line 203
{ } 
#endif
#line 87 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.h"
extern "C" {
#line 1139
}
#line 1147
static __inline double fma(double a, double b, double c, cudaRoundMode mode); 
#line 1149
static __inline double dmul(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1151
static __inline double dadd(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1153
static __inline double dsub(double a, double b, cudaRoundMode mode = cudaRoundNearest); 
#line 1155
static __inline int double2int(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1157
static __inline unsigned double2uint(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1159
static __inline __int64 double2ll(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1161
static __inline unsigned __int64 double2ull(double a, cudaRoundMode mode = cudaRoundZero); 
#line 1163
static __inline double ll2double(__int64 a, cudaRoundMode mode = cudaRoundNearest); 
#line 1165
static __inline double ull2double(unsigned __int64 a, cudaRoundMode mode = cudaRoundNearest); 
#line 1167
static __inline double int2double(int a, cudaRoundMode mode = cudaRoundNearest); 
#line 1169
static __inline double uint2double(unsigned a, cudaRoundMode mode = cudaRoundNearest); 
#line 1171
static __inline double float2double(float a, cudaRoundMode mode = cudaRoundNearest); 
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double fma(double a, double b, double c, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)c;(void)mode;::exit(___);}
#if 0
#line 94
{ 
#line 95
return (mode == (cudaRoundZero)) ? __fma_rz(a, b, c) : ((mode == (cudaRoundPosInf)) ? __fma_ru(a, b, c) : ((mode == (cudaRoundMinInf)) ? __fma_rd(a, b, c) : __fma_rn(a, b, c))); 
#line 99
} 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double dmul(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 102
{ 
#line 103
return (mode == (cudaRoundZero)) ? __dmul_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dmul_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dmul_rd(a, b) : __dmul_rn(a, b))); 
#line 107
} 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double dadd(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 110
{ 
#line 111
return (mode == (cudaRoundZero)) ? __dadd_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dadd_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dadd_rd(a, b) : __dadd_rn(a, b))); 
#line 115
} 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double dsub(double a, double b, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)b;(void)mode;::exit(___);}
#if 0
#line 118
{ 
#line 119
return (mode == (cudaRoundZero)) ? __dsub_rz(a, b) : ((mode == (cudaRoundPosInf)) ? __dsub_ru(a, b) : ((mode == (cudaRoundMinInf)) ? __dsub_rd(a, b) : __dsub_rn(a, b))); 
#line 123
} 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline int double2int(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 126
{ 
#line 127
return (mode == (cudaRoundNearest)) ? __double2int_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2int_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2int_rd(a) : __double2int_rz(a))); 
#line 131
} 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline unsigned double2uint(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 134
{ 
#line 135
return (mode == (cudaRoundNearest)) ? __double2uint_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2uint_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2uint_rd(a) : __double2uint_rz(a))); 
#line 139
} 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline __int64 double2ll(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 142
{ 
#line 143
return (mode == (cudaRoundNearest)) ? __double2ll_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ll_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ll_rd(a) : __double2ll_rz(a))); 
#line 147
} 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline unsigned __int64 double2ull(double a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 150
{ 
#line 151
return (mode == (cudaRoundNearest)) ? __double2ull_rn(a) : ((mode == (cudaRoundPosInf)) ? __double2ull_ru(a) : ((mode == (cudaRoundMinInf)) ? __double2ull_rd(a) : __double2ull_rz(a))); 
#line 155
} 
#endif
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double ll2double(__int64 a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 158
{ 
#line 159
return (mode == (cudaRoundZero)) ? __ll2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ll2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ll2double_rd(a) : __ll2double_rn(a))); 
#line 163
} 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double ull2double(unsigned __int64 a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 166
{ 
#line 167
return (mode == (cudaRoundZero)) ? __ull2double_rz(a) : ((mode == (cudaRoundPosInf)) ? __ull2double_ru(a) : ((mode == (cudaRoundMinInf)) ? __ull2double_rd(a) : __ull2double_rn(a))); 
#line 171
} 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double int2double(int a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 174
{ 
#line 175
return (double)a; 
#line 176
} 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double uint2double(unsigned a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 179
{ 
#line 180
return (double)a; 
#line 181
} 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\device_double_functions.hpp"
static __inline double float2double(float a, cudaRoundMode mode) {int volatile ___ = 1;(void)a;(void)mode;::exit(___);}
#if 0
#line 184
{ 
#line 185
return (double)a; 
#line 186
} 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_atomic_functions.h"
static __inline float atomicAdd(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicMin(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicMax(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicAnd(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicOr(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline __int64 atomicXor(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 118
{ } 
#endif
#line 120 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicMin(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 120
{ } 
#endif
#line 122 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicMax(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 122
{ } 
#endif
#line 124 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicAnd(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 124
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicOr(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_atomic_functions.h"
static __inline unsigned __int64 atomicXor(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 307 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 307
{ } 
#endif
#line 310 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAdd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 310
{ } 
#endif
#line 313 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAdd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 313
{ } 
#endif
#line 316 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAdd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 316
{ } 
#endif
#line 319 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAdd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 319
{ } 
#endif
#line 322 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAdd_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 322
{ } 
#endif
#line 325 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAdd_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 325
{ } 
#endif
#line 328 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicAdd_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 328
{ } 
#endif
#line 331 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicAdd_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 331
{ } 
#endif
#line 334 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd_block(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 334
{ } 
#endif
#line 337 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline double atomicAdd_system(double *address, double val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 337
{ } 
#endif
#line 340 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicSub_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 340
{ } 
#endif
#line 343 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicSub_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 343
{ } 
#endif
#line 346 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicSub_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 346
{ } 
#endif
#line 349 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicSub_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 349
{ } 
#endif
#line 352 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicExch_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 352
{ } 
#endif
#line 355 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicExch_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 355
{ } 
#endif
#line 358 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicExch_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 358
{ } 
#endif
#line 361 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicExch_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 361
{ } 
#endif
#line 364 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicExch_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 364
{ } 
#endif
#line 367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicExch_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 367
{ } 
#endif
#line 370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicExch_block(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 370
{ } 
#endif
#line 373 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline float atomicExch_system(float *address, float val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 373
{ } 
#endif
#line 376 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMin_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 376
{ } 
#endif
#line 379 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMin_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 379
{ } 
#endif
#line 382 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMin_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 382
{ } 
#endif
#line 385 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMin_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 385
{ } 
#endif
#line 388 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMin_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 388
{ } 
#endif
#line 391 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMin_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 391
{ } 
#endif
#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMin_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 394
{ } 
#endif
#line 397 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMin_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 397
{ } 
#endif
#line 400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMax_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 400
{ } 
#endif
#line 403 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicMax_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 403
{ } 
#endif
#line 406 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMax_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 406
{ } 
#endif
#line 409 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicMax_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 409
{ } 
#endif
#line 412 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMax_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 412
{ } 
#endif
#line 415 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicMax_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 415
{ } 
#endif
#line 418 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMax_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 418
{ } 
#endif
#line 421 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicMax_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 421
{ } 
#endif
#line 424 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicInc_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 424
{ } 
#endif
#line 427 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicInc_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 427
{ } 
#endif
#line 430 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicDec_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 430
{ } 
#endif
#line 433 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicDec_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 433
{ } 
#endif
#line 436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicCAS_block(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 436
{ } 
#endif
#line 439 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicCAS_system(int *address, int compare, int val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 439
{ } 
#endif
#line 442 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicCAS_block(unsigned *address, unsigned compare, unsigned 
#line 443
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 443
{ } 
#endif
#line 446 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicCAS_system(unsigned *address, unsigned compare, unsigned 
#line 447
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 447
{ } 
#endif
#line 450 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicCAS_block(unsigned __int64 *address, unsigned __int64 
#line 451
compare, unsigned __int64 
#line 452
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 452
{ } 
#endif
#line 455 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicCAS_system(unsigned __int64 *address, unsigned __int64 
#line 456
compare, unsigned __int64 
#line 457
val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 457
{ } 
#endif
#line 460 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAnd_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 460
{ } 
#endif
#line 463 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicAnd_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 463
{ } 
#endif
#line 466 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicAnd_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 466
{ } 
#endif
#line 469 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicAnd_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 469
{ } 
#endif
#line 472 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAnd_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 472
{ } 
#endif
#line 475 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicAnd_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 475
{ } 
#endif
#line 478 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAnd_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 478
{ } 
#endif
#line 481 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicAnd_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 481
{ } 
#endif
#line 484 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicOr_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 484
{ } 
#endif
#line 487 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicOr_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 487
{ } 
#endif
#line 490 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicOr_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 490
{ } 
#endif
#line 493 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicOr_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 493
{ } 
#endif
#line 496 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicOr_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 496
{ } 
#endif
#line 499 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicOr_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 499
{ } 
#endif
#line 502 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicOr_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 502
{ } 
#endif
#line 505 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicOr_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 505
{ } 
#endif
#line 508 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicXor_block(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 508
{ } 
#endif
#line 511 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline int atomicXor_system(int *address, int val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 511
{ } 
#endif
#line 514 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicXor_block(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 514
{ } 
#endif
#line 517 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline __int64 atomicXor_system(__int64 *address, __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 517
{ } 
#endif
#line 520 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicXor_block(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 520
{ } 
#endif
#line 523 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned atomicXor_system(unsigned *address, unsigned val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 523
{ } 
#endif
#line 526 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicXor_block(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 526
{ } 
#endif
#line 529 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_60_atomic_functions.h"
static __inline unsigned __int64 atomicXor_system(unsigned __int64 *address, unsigned __int64 val) {int volatile ___ = 1;(void)address;(void)val;::exit(___);}
#if 0
#line 529
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
extern "C" {
#line 1510
}
#line 1522 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
__declspec(deprecated("__ballot() is deprecated in favor of __ballot_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to" " suppress this warning).")) static __inline unsigned ballot(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1522
{ } 
#endif
#line 1524 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline int syncthreads_count(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1524
{ } 
#endif
#line 1526 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline bool syncthreads_and(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1526
{ } 
#endif
#line 1528 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline bool syncthreads_or(bool pred) {int volatile ___ = 1;(void)pred;::exit(___);}
#if 0
#line 1528
{ } 
#endif
#line 1533 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isGlobal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1533
{ } 
#endif
#line 1534 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1534
{ } 
#endif
#line 1535 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isConstant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1535
{ } 
#endif
#line 1536 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isLocal(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1536
{ } 
#endif
#line 1538 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline unsigned __isGridConstant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1538
{ } 
#endif
#line 1540 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_global(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1540
{ } 
#endif
#line 1541 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_shared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1541
{ } 
#endif
#line 1542 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_constant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1542
{ } 
#endif
#line 1543 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_local(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1543
{ } 
#endif
#line 1545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline size_t __cvta_generic_to_grid_constant(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 1545
{ } 
#endif
#line 1548 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_global_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1548
{ } 
#endif
#line 1549 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_shared_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1549
{ } 
#endif
#line 1550 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_constant_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1550
{ } 
#endif
#line 1551 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_local_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1551
{ } 
#endif
#line 1553 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_20_intrinsics.h"
static __inline void *__cvta_grid_constant_to_generic(size_t rawbits) {int volatile ___ = 1;(void)rawbits;::exit(___);}
#if 0
#line 1553
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __fns(unsigned mask, unsigned base, int offset) {int volatile ___ = 1;(void)mask;(void)base;(void)offset;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline void __barrier_sync(unsigned id) {int volatile ___ = 1;(void)id;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline void __barrier_sync_count(unsigned id, unsigned cnt) {int volatile ___ = 1;(void)id;(void)cnt;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline void __syncwarp(unsigned mask = 4294967295U) {int volatile ___ = 1;(void)mask;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __all_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __any_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __uni_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 114
{ } 
#endif
#line 115 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __ballot_sync(unsigned mask, int pred) {int volatile ___ = 1;(void)mask;(void)pred;::exit(___);}
#if 0
#line 115
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __activemask() {int volatile ___ = 1;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 125 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline int __shfl(int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 125
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned __shfl(unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline int __shfl_up(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 127
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned __shfl_up(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline int __shfl_down(int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 130 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned __shfl_down(unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 130
{ } 
#endif
#line 131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline int __shfl_xor(int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 131
{ } 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned __shfl_xor(unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 132
{ } 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline float __shfl(float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 133
{ } 
#endif
#line 134 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline float __shfl_up(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 134
{ } 
#endif
#line 135 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline float __shfl_down(float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 135
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline float __shfl_xor(float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 139 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_sync(unsigned mask, int var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 139
{ } 
#endif
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_sync(unsigned mask, unsigned var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 140
{ } 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_up_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 141
{ } 
#endif
#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_up_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 142
{ } 
#endif
#line 143 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_down_sync(unsigned mask, int var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 143
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_down_sync(unsigned mask, unsigned var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 145 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline int __shfl_xor_sync(unsigned mask, int var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 145
{ } 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __shfl_xor_sync(unsigned mask, unsigned var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 146
{ } 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_sync(unsigned mask, float var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 147
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_up_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_down_sync(unsigned mask, float var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 149
{ } 
#endif
#line 150 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline float __shfl_xor_sync(unsigned mask, float var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 150
{ } 
#endif
#line 154 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned __int64 __shfl(unsigned __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 154
{ } 
#endif
#line 155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline __int64 __shfl(__int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 155
{ } 
#endif
#line 156 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline __int64 __shfl_up(__int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 156
{ } 
#endif
#line 157 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned __int64 __shfl_up(unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 157
{ } 
#endif
#line 158 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline __int64 __shfl_down(__int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 158
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned __int64 __shfl_down(unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 160 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline __int64 __shfl_xor(__int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 160
{ } 
#endif
#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned __int64 __shfl_xor(unsigned __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 161
{ } 
#endif
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline double __shfl(double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 162
{ } 
#endif
#line 163 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline double __shfl_up(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 163
{ } 
#endif
#line 164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline double __shfl_down(double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 164
{ } 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline double __shfl_xor(double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 165
{ } 
#endif
#line 168 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_sync(unsigned mask, __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 168
{ } 
#endif
#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_sync(unsigned mask, unsigned __int64 var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 169
{ } 
#endif
#line 170 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_up_sync(unsigned mask, __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 170
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_up_sync(unsigned mask, unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_down_sync(unsigned mask, __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 172
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_down_sync(unsigned mask, unsigned __int64 var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 174 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline __int64 __shfl_xor_sync(unsigned mask, __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 174
{ } 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned __int64 __shfl_xor_sync(unsigned mask, unsigned __int64 var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 175
{ } 
#endif
#line 176 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_sync(unsigned mask, double var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 176
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_up_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_down_sync(unsigned mask, double var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 178
{ } 
#endif
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline double __shfl_xor_sync(unsigned mask, double var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 179
{ } 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline long __shfl(long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 183
{ } 
#endif
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl() is deprecated in favor of __shfl_sync() and may be removed in a future release (Use -Wno-deprecated-declarations to sup" "press this warning).")) static __inline unsigned long __shfl(unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 184
{ } 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline long __shfl_up(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 185
{ } 
#endif
#line 186 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_up() is deprecated in favor of __shfl_up_sync() and may be removed in a future release (Use -Wno-deprecated-declarations " "to suppress this warning).")) static __inline unsigned long __shfl_up(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 186
{ } 
#endif
#line 187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline long __shfl_down(long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 187
{ } 
#endif
#line 188 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_down() is deprecated in favor of __shfl_down_sync() and may be removed in a future release (Use -Wno-deprecated-declarati" "ons to suppress this warning).")) static __inline unsigned long __shfl_down(unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 188
{ } 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline long __shfl_xor(long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 189
{ } 
#endif
#line 190 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
__declspec(deprecated("__shfl_xor() is deprecated in favor of __shfl_xor_sync() and may be removed in a future release (Use -Wno-deprecated-declaration" "s to suppress this warning).")) static __inline unsigned long __shfl_xor(unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 190
{ } 
#endif
#line 193 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_sync(unsigned mask, long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 193
{ } 
#endif
#line 194 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_sync(unsigned mask, unsigned long var, int srcLane, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)srcLane;(void)width;::exit(___);}
#if 0
#line 194
{ } 
#endif
#line 195 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_up_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 195
{ } 
#endif
#line 196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_up_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 196
{ } 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_down_sync(unsigned mask, long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 197
{ } 
#endif
#line 198 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_down_sync(unsigned mask, unsigned long var, unsigned delta, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)delta;(void)width;::exit(___);}
#if 0
#line 198
{ } 
#endif
#line 199 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline long __shfl_xor_sync(unsigned mask, long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 199
{ } 
#endif
#line 200 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_30_intrinsics.h"
static __inline unsigned long __shfl_xor_sync(unsigned mask, unsigned long var, int laneMask, int width = 32) {int volatile ___ = 1;(void)mask;(void)var;(void)laneMask;(void)width;::exit(___);}
#if 0
#line 200
{ } 
#endif
#line 87 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 87
{ } 
#endif
#line 88 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 88
{ } 
#endif
#line 90 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 90
{ } 
#endif
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 91
{ } 
#endif
#line 92 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 92
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldg(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldg(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 106
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 112
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 115 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 115
{ } 
#endif
#line 116 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 116
{ } 
#endif
#line 117 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 117
{ } 
#endif
#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 118
{ } 
#endif
#line 119 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 119
{ } 
#endif
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcg(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 123
{ } 
#endif
#line 124 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcg(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 124
{ } 
#endif
#line 126 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcg(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 126
{ } 
#endif
#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcg(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 127
{ } 
#endif
#line 128 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcg(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 128
{ } 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcg(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 129
{ } 
#endif
#line 130 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcg(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 130
{ } 
#endif
#line 131 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcg(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 131
{ } 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcg(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 132
{ } 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcg(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 133
{ } 
#endif
#line 134 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcg(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 134
{ } 
#endif
#line 135 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcg(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 135
{ } 
#endif
#line 136 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcg(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 136
{ } 
#endif
#line 137 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcg(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 137
{ } 
#endif
#line 139 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcg(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 139
{ } 
#endif
#line 140 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcg(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 140
{ } 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcg(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 141
{ } 
#endif
#line 142 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcg(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 142
{ } 
#endif
#line 143 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcg(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 143
{ } 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcg(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 144
{ } 
#endif
#line 145 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcg(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 145
{ } 
#endif
#line 146 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcg(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 146
{ } 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcg(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 147
{ } 
#endif
#line 148 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcg(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 148
{ } 
#endif
#line 149 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcg(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 149
{ } 
#endif
#line 151 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcg(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 151
{ } 
#endif
#line 152 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcg(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 152
{ } 
#endif
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcg(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 153
{ } 
#endif
#line 154 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcg(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 154
{ } 
#endif
#line 155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcg(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 155
{ } 
#endif
#line 159 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldca(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 159
{ } 
#endif
#line 160 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldca(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 160
{ } 
#endif
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldca(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 162
{ } 
#endif
#line 163 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldca(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 163
{ } 
#endif
#line 164 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldca(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 164
{ } 
#endif
#line 165 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldca(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 165
{ } 
#endif
#line 166 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldca(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 166
{ } 
#endif
#line 167 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldca(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 167
{ } 
#endif
#line 168 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldca(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 168
{ } 
#endif
#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldca(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 169
{ } 
#endif
#line 170 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldca(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 170
{ } 
#endif
#line 171 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldca(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 171
{ } 
#endif
#line 172 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldca(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 172
{ } 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldca(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 173
{ } 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldca(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 175
{ } 
#endif
#line 176 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldca(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 176
{ } 
#endif
#line 177 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldca(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 177
{ } 
#endif
#line 178 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldca(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 178
{ } 
#endif
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldca(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 179
{ } 
#endif
#line 180 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldca(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 180
{ } 
#endif
#line 181 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldca(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 181
{ } 
#endif
#line 182 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldca(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 182
{ } 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldca(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 183
{ } 
#endif
#line 184 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldca(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 184
{ } 
#endif
#line 185 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldca(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 185
{ } 
#endif
#line 187 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldca(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 187
{ } 
#endif
#line 188 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldca(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 188
{ } 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldca(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 189
{ } 
#endif
#line 190 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldca(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 190
{ } 
#endif
#line 191 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldca(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 191
{ } 
#endif
#line 195 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcs(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 195
{ } 
#endif
#line 196 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcs(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 196
{ } 
#endif
#line 198 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcs(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 198
{ } 
#endif
#line 199 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcs(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 199
{ } 
#endif
#line 200 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcs(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 200
{ } 
#endif
#line 201 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcs(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 201
{ } 
#endif
#line 202 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcs(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 202
{ } 
#endif
#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcs(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 203
{ } 
#endif
#line 204 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcs(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 204
{ } 
#endif
#line 205 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcs(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 205
{ } 
#endif
#line 206 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcs(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 206
{ } 
#endif
#line 207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcs(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 207
{ } 
#endif
#line 208 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcs(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 208
{ } 
#endif
#line 209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcs(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 209
{ } 
#endif
#line 211 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcs(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 211
{ } 
#endif
#line 212 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcs(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 212
{ } 
#endif
#line 213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcs(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 213
{ } 
#endif
#line 214 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcs(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 214
{ } 
#endif
#line 215 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcs(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 215
{ } 
#endif
#line 216 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcs(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 216
{ } 
#endif
#line 217 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcs(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 217
{ } 
#endif
#line 218 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcs(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 218
{ } 
#endif
#line 219 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcs(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 219
{ } 
#endif
#line 220 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcs(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 220
{ } 
#endif
#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcs(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 221
{ } 
#endif
#line 223 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcs(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 223
{ } 
#endif
#line 224 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcs(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 224
{ } 
#endif
#line 225 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcs(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 225
{ } 
#endif
#line 226 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcs(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 226
{ } 
#endif
#line 227 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcs(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 227
{ } 
#endif
#line 231 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldlu(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 231
{ } 
#endif
#line 232 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldlu(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 232
{ } 
#endif
#line 234 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldlu(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 234
{ } 
#endif
#line 235 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldlu(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 235
{ } 
#endif
#line 236 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldlu(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 236
{ } 
#endif
#line 237 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldlu(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 237
{ } 
#endif
#line 238 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldlu(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 238
{ } 
#endif
#line 239 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldlu(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 239
{ } 
#endif
#line 240 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldlu(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 240
{ } 
#endif
#line 241 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldlu(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 241
{ } 
#endif
#line 242 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldlu(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 242
{ } 
#endif
#line 243 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldlu(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 243
{ } 
#endif
#line 244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldlu(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 244
{ } 
#endif
#line 245 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldlu(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 245
{ } 
#endif
#line 247 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldlu(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 247
{ } 
#endif
#line 248 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldlu(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 248
{ } 
#endif
#line 249 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldlu(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 249
{ } 
#endif
#line 250 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldlu(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 250
{ } 
#endif
#line 251 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldlu(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 251
{ } 
#endif
#line 252 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldlu(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 252
{ } 
#endif
#line 253 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldlu(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 253
{ } 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldlu(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 254
{ } 
#endif
#line 255 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldlu(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 255
{ } 
#endif
#line 256 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldlu(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 256
{ } 
#endif
#line 257 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldlu(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 257
{ } 
#endif
#line 259 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldlu(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 259
{ } 
#endif
#line 260 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldlu(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 260
{ } 
#endif
#line 261 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldlu(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 261
{ } 
#endif
#line 262 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldlu(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 262
{ } 
#endif
#line 263 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldlu(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 263
{ } 
#endif
#line 267 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline long __ldcv(const long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 267
{ } 
#endif
#line 268 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned long __ldcv(const unsigned long *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 268
{ } 
#endif
#line 270 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char __ldcv(const char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 270
{ } 
#endif
#line 271 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline signed char __ldcv(const signed char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 271
{ } 
#endif
#line 272 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short __ldcv(const short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 272
{ } 
#endif
#line 273 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int __ldcv(const int *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 273
{ } 
#endif
#line 274 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline __int64 __ldcv(const __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 274
{ } 
#endif
#line 275 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char2 __ldcv(const char2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 275
{ } 
#endif
#line 276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline char4 __ldcv(const char4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 276
{ } 
#endif
#line 277 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short2 __ldcv(const short2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 277
{ } 
#endif
#line 278 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline short4 __ldcv(const short4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 278
{ } 
#endif
#line 279 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int2 __ldcv(const int2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 279
{ } 
#endif
#line 280 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline int4 __ldcv(const int4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 280
{ } 
#endif
#line 281 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline longlong2 __ldcv(const longlong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 281
{ } 
#endif
#line 283 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned char __ldcv(const unsigned char *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 283
{ } 
#endif
#line 284 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned short __ldcv(const unsigned short *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 284
{ } 
#endif
#line 285 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __ldcv(const unsigned *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 285
{ } 
#endif
#line 286 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __int64 __ldcv(const unsigned __int64 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 286
{ } 
#endif
#line 287 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar2 __ldcv(const uchar2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 287
{ } 
#endif
#line 288 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uchar4 __ldcv(const uchar4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 288
{ } 
#endif
#line 289 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort2 __ldcv(const ushort2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 289
{ } 
#endif
#line 290 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ushort4 __ldcv(const ushort4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 290
{ } 
#endif
#line 291 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint2 __ldcv(const uint2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 291
{ } 
#endif
#line 292 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline uint4 __ldcv(const uint4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 292
{ } 
#endif
#line 293 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline ulonglong2 __ldcv(const ulonglong2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 293
{ } 
#endif
#line 295 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float __ldcv(const float *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 295
{ } 
#endif
#line 296 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double __ldcv(const double *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 296
{ } 
#endif
#line 297 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float2 __ldcv(const float2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 297
{ } 
#endif
#line 298 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline float4 __ldcv(const float4 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 298
{ } 
#endif
#line 299 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline double2 __ldcv(const double2 *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 299
{ } 
#endif
#line 303 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 303
{ } 
#endif
#line 304 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 304
{ } 
#endif
#line 306 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 306
{ } 
#endif
#line 307 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 307
{ } 
#endif
#line 308 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 308
{ } 
#endif
#line 309 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 309
{ } 
#endif
#line 310 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 310
{ } 
#endif
#line 311 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 311
{ } 
#endif
#line 312 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 312
{ } 
#endif
#line 313 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 313
{ } 
#endif
#line 314 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 314
{ } 
#endif
#line 315 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 315
{ } 
#endif
#line 316 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 316
{ } 
#endif
#line 317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 317
{ } 
#endif
#line 319 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 319
{ } 
#endif
#line 320 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 320
{ } 
#endif
#line 321 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 321
{ } 
#endif
#line 322 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 322
{ } 
#endif
#line 323 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 323
{ } 
#endif
#line 324 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 324
{ } 
#endif
#line 325 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 325
{ } 
#endif
#line 326 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 326
{ } 
#endif
#line 327 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 327
{ } 
#endif
#line 328 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 328
{ } 
#endif
#line 329 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 329
{ } 
#endif
#line 331 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 331
{ } 
#endif
#line 332 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 332
{ } 
#endif
#line 333 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 333
{ } 
#endif
#line 334 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 334
{ } 
#endif
#line 335 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwb(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 335
{ } 
#endif
#line 339 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 339
{ } 
#endif
#line 340 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 340
{ } 
#endif
#line 342 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 342
{ } 
#endif
#line 343 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 343
{ } 
#endif
#line 344 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 344
{ } 
#endif
#line 345 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 345
{ } 
#endif
#line 346 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 346
{ } 
#endif
#line 347 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 347
{ } 
#endif
#line 348 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 348
{ } 
#endif
#line 349 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 349
{ } 
#endif
#line 350 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 350
{ } 
#endif
#line 351 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 351
{ } 
#endif
#line 352 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 352
{ } 
#endif
#line 353 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 353
{ } 
#endif
#line 355 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 355
{ } 
#endif
#line 356 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 356
{ } 
#endif
#line 357 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 357
{ } 
#endif
#line 358 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 358
{ } 
#endif
#line 359 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 359
{ } 
#endif
#line 360 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 360
{ } 
#endif
#line 361 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 361
{ } 
#endif
#line 362 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 362
{ } 
#endif
#line 363 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 363
{ } 
#endif
#line 364 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 364
{ } 
#endif
#line 365 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 365
{ } 
#endif
#line 367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 367
{ } 
#endif
#line 368 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 368
{ } 
#endif
#line 369 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 369
{ } 
#endif
#line 370 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 370
{ } 
#endif
#line 371 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcg(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 371
{ } 
#endif
#line 375 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 375
{ } 
#endif
#line 376 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 376
{ } 
#endif
#line 378 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 378
{ } 
#endif
#line 379 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 379
{ } 
#endif
#line 380 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 380
{ } 
#endif
#line 381 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 381
{ } 
#endif
#line 382 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 382
{ } 
#endif
#line 383 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 383
{ } 
#endif
#line 384 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 384
{ } 
#endif
#line 385 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 385
{ } 
#endif
#line 386 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 386
{ } 
#endif
#line 387 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 387
{ } 
#endif
#line 388 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 388
{ } 
#endif
#line 389 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 389
{ } 
#endif
#line 391 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 391
{ } 
#endif
#line 392 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 392
{ } 
#endif
#line 393 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 393
{ } 
#endif
#line 394 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 394
{ } 
#endif
#line 395 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 395
{ } 
#endif
#line 396 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 396
{ } 
#endif
#line 397 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 397
{ } 
#endif
#line 398 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 398
{ } 
#endif
#line 399 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 399
{ } 
#endif
#line 400 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 400
{ } 
#endif
#line 401 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 401
{ } 
#endif
#line 403 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 403
{ } 
#endif
#line 404 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 404
{ } 
#endif
#line 405 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 405
{ } 
#endif
#line 406 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 406
{ } 
#endif
#line 407 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stcs(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 407
{ } 
#endif
#line 411 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(long *ptr, long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 411
{ } 
#endif
#line 412 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned long *ptr, unsigned long value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 412
{ } 
#endif
#line 414 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char *ptr, char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 414
{ } 
#endif
#line 415 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(signed char *ptr, signed char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 415
{ } 
#endif
#line 416 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short *ptr, short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 416
{ } 
#endif
#line 417 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int *ptr, int value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 417
{ } 
#endif
#line 418 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(__int64 *ptr, __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 418
{ } 
#endif
#line 419 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char2 *ptr, char2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 419
{ } 
#endif
#line 420 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(char4 *ptr, char4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 420
{ } 
#endif
#line 421 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short2 *ptr, short2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 421
{ } 
#endif
#line 422 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(short4 *ptr, short4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 422
{ } 
#endif
#line 423 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int2 *ptr, int2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 423
{ } 
#endif
#line 424 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(int4 *ptr, int4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 424
{ } 
#endif
#line 425 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(longlong2 *ptr, longlong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 425
{ } 
#endif
#line 427 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned char *ptr, unsigned char value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 427
{ } 
#endif
#line 428 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned short *ptr, unsigned short value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 428
{ } 
#endif
#line 429 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned *ptr, unsigned value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 429
{ } 
#endif
#line 430 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(unsigned __int64 *ptr, unsigned __int64 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 430
{ } 
#endif
#line 431 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uchar2 *ptr, uchar2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 431
{ } 
#endif
#line 432 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uchar4 *ptr, uchar4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 432
{ } 
#endif
#line 433 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ushort2 *ptr, ushort2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 433
{ } 
#endif
#line 434 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ushort4 *ptr, ushort4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 434
{ } 
#endif
#line 435 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uint2 *ptr, uint2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 435
{ } 
#endif
#line 436 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(uint4 *ptr, uint4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 436
{ } 
#endif
#line 437 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(ulonglong2 *ptr, ulonglong2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 437
{ } 
#endif
#line 439 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float *ptr, float value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 439
{ } 
#endif
#line 440 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(double *ptr, double value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 440
{ } 
#endif
#line 441 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float2 *ptr, float2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 441
{ } 
#endif
#line 442 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(float4 *ptr, float4 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 442
{ } 
#endif
#line 443 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline void __stwt(double2 *ptr, double2 value) {int volatile ___ = 1;(void)ptr;(void)value;::exit(___);}
#if 0
#line 443
{ } 
#endif
#line 460 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_l(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 460
{ } 
#endif
#line 472 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_lc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 472
{ } 
#endif
#line 485 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_r(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 485
{ } 
#endif
#line 497 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_32_intrinsics.h"
static __inline unsigned __funnelshift_rc(unsigned lo, unsigned hi, unsigned shift) {int volatile ___ = 1;(void)lo;(void)hi;(void)shift;::exit(___);}
#if 0
#line 497
{ } 
#endif
#line 89 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_lo(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 89
{ } 
#endif
#line 90 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_lo(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 90
{ } 
#endif
#line 92 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_lo(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 92
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_lo(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_hi(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_hi(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp2a_hi(short2 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp2a_hi(ushort2 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp4a(int srcA, int srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 106
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp4a(unsigned srcA, unsigned srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline int __dp4a(char4 srcA, char4 srcB, int c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 110 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\sm_61_intrinsics.h"
static __inline unsigned __dp4a(uchar4 srcA, uchar4 srcB, unsigned c) {int volatile ___ = 1;(void)srcA;(void)srcB;(void)c;::exit(___);}
#if 0
#line 110
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, long value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, unsigned __int64 value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, __int64 value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, float value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_any_sync(unsigned mask, double value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, int value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 105 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, long value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 105
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, unsigned __int64 value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 106
{ } 
#endif
#line 107 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, __int64 value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 107
{ } 
#endif
#line 108 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, float value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 108
{ } 
#endif
#line 109 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned __match_all_sync(unsigned mask, double value, int *pred) {int volatile ___ = 1;(void)mask;(void)value;(void)pred;::exit(___);}
#if 0
#line 109
{ } 
#endif
#line 111 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline void __nanosleep(unsigned ns) {int volatile ___ = 1;(void)ns;::exit(___);}
#if 0
#line 111
{ } 
#endif
#line 113 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_70_rt.h"
static __inline unsigned short atomicCAS(unsigned short *address, unsigned short compare, unsigned short val) {int volatile ___ = 1;(void)address;(void)compare;(void)val;::exit(___);}
#if 0
#line 113
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_add_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_min_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_max_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_add_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_min_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline int __reduce_max_sync(unsigned mask, int value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_and_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_or_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
static __inline unsigned __reduce_xor_sync(unsigned mask, unsigned value) {int volatile ___ = 1;(void)mask;(void)value;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 106 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
extern "C" {
#line 107
inline void *__nv_associate_access_property(const void *ptr, unsigned __int64 
#line 108
property) {int volatile ___ = 1;(void)ptr;(void)property;::exit(___);}
#if 0
#line 108
{ 
#line 109
extern void *__nv_associate_access_property_impl(const void *, unsigned __int64); 
#line 111
return __nv_associate_access_property_impl(ptr, property); 
#line 112
} 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_4(void *dst, const void *
#line 115
src, unsigned 
#line 116
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 116
{ 
#line 117
extern void __nv_memcpy_async_shared_global_4_impl(void *, const void *, unsigned); 
#line 120
__nv_memcpy_async_shared_global_4_impl(dst, src, src_size); 
#line 121
} 
#endif
#line 123 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_8(void *dst, const void *
#line 124
src, unsigned 
#line 125
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 125
{ 
#line 126
extern void __nv_memcpy_async_shared_global_8_impl(void *, const void *, unsigned); 
#line 129
__nv_memcpy_async_shared_global_8_impl(dst, src, src_size); 
#line 130
} 
#endif
#line 132 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
inline void __nv_memcpy_async_shared_global_16(void *dst, const void *
#line 133
src, unsigned 
#line 134
src_size) {int volatile ___ = 1;(void)dst;(void)src;(void)src_size;::exit(___);}
#if 0
#line 134
{ 
#line 135
extern void __nv_memcpy_async_shared_global_16_impl(void *, const void *, unsigned); 
#line 138
__nv_memcpy_async_shared_global_16_impl(dst, src, src_size); 
#line 139
} 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_80_rt.h"
}
#line 89 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __isCtaShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 89
{ } 
#endif
#line 90 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __isClusterShared(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 90
{ } 
#endif
#line 91 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline void *__cluster_map_shared_rank(const void *ptr, unsigned target_block_rank) {int volatile ___ = 1;(void)ptr;(void)target_block_rank;::exit(___);}
#if 0
#line 91
{ } 
#endif
#line 92 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __cluster_query_shared_rank(const void *ptr) {int volatile ___ = 1;(void)ptr;::exit(___);}
#if 0
#line 92
{ } 
#endif
#line 93 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline uint2 __cluster_map_shared_multicast(const void *ptr, unsigned cluster_cta_mask) {int volatile ___ = 1;(void)ptr;(void)cluster_cta_mask;::exit(___);}
#if 0
#line 93
{ } 
#endif
#line 94 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterDimIsSpecified() {int volatile ___ = 1;::exit(___);}
#if 0
#line 94
{ } 
#endif
#line 95 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterDim() {int volatile ___ = 1;::exit(___);}
#if 0
#line 95
{ } 
#endif
#line 96 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterRelativeBlockIdx() {int volatile ___ = 1;::exit(___);}
#if 0
#line 96
{ } 
#endif
#line 97 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterGridDimInClusters() {int volatile ___ = 1;::exit(___);}
#if 0
#line 97
{ } 
#endif
#line 98 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline dim3 __clusterIdx() {int volatile ___ = 1;::exit(___);}
#if 0
#line 98
{ } 
#endif
#line 99 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterRelativeBlockRank() {int volatile ___ = 1;::exit(___);}
#if 0
#line 99
{ } 
#endif
#line 100 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline unsigned __clusterSizeInBlocks() {int volatile ___ = 1;::exit(___);}
#if 0
#line 100
{ } 
#endif
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_arrive() {int volatile ___ = 1;::exit(___);}
#if 0
#line 101
{ } 
#endif
#line 102 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_arrive_relaxed() {int volatile ___ = 1;::exit(___);}
#if 0
#line 102
{ } 
#endif
#line 103 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline void __cluster_barrier_wait() {int volatile ___ = 1;::exit(___);}
#if 0
#line 103
{ } 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt\\sm_90_rt.h"
static __inline void __threadfence_cluster() {int volatile ___ = 1;::exit(___);}
#if 0
#line 104
{ } 
#endif
#line 65 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> struct __nv_itex_trait { }; 
#line 66
template<> struct __nv_itex_trait< char>  { typedef void type; }; 
#line 67
template<> struct __nv_itex_trait< signed char>  { typedef void type; }; 
#line 68
template<> struct __nv_itex_trait< char1>  { typedef void type; }; 
#line 69
template<> struct __nv_itex_trait< char2>  { typedef void type; }; 
#line 70
template<> struct __nv_itex_trait< char4>  { typedef void type; }; 
#line 71
template<> struct __nv_itex_trait< unsigned char>  { typedef void type; }; 
#line 72
template<> struct __nv_itex_trait< uchar1>  { typedef void type; }; 
#line 73
template<> struct __nv_itex_trait< uchar2>  { typedef void type; }; 
#line 74
template<> struct __nv_itex_trait< uchar4>  { typedef void type; }; 
#line 75
template<> struct __nv_itex_trait< short>  { typedef void type; }; 
#line 76
template<> struct __nv_itex_trait< short1>  { typedef void type; }; 
#line 77
template<> struct __nv_itex_trait< short2>  { typedef void type; }; 
#line 78
template<> struct __nv_itex_trait< short4>  { typedef void type; }; 
#line 79
template<> struct __nv_itex_trait< unsigned short>  { typedef void type; }; 
#line 80
template<> struct __nv_itex_trait< ushort1>  { typedef void type; }; 
#line 81
template<> struct __nv_itex_trait< ushort2>  { typedef void type; }; 
#line 82
template<> struct __nv_itex_trait< ushort4>  { typedef void type; }; 
#line 83
template<> struct __nv_itex_trait< int>  { typedef void type; }; 
#line 84
template<> struct __nv_itex_trait< int1>  { typedef void type; }; 
#line 85
template<> struct __nv_itex_trait< int2>  { typedef void type; }; 
#line 86
template<> struct __nv_itex_trait< int4>  { typedef void type; }; 
#line 87
template<> struct __nv_itex_trait< unsigned>  { typedef void type; }; 
#line 88
template<> struct __nv_itex_trait< uint1>  { typedef void type; }; 
#line 89
template<> struct __nv_itex_trait< uint2>  { typedef void type; }; 
#line 90
template<> struct __nv_itex_trait< uint4>  { typedef void type; }; 
#line 92
template<> struct __nv_itex_trait< long>  { typedef void type; }; 
#line 93
template<> struct __nv_itex_trait< long1>  { typedef void type; }; 
#line 94
template<> struct __nv_itex_trait< long2>  { typedef void type; }; 
#line 95
template<> struct __nv_itex_trait< long4>  { typedef void type; }; 
#line 96
template<> struct __nv_itex_trait< unsigned long>  { typedef void type; }; 
#line 97
template<> struct __nv_itex_trait< ulong1>  { typedef void type; }; 
#line 98
template<> struct __nv_itex_trait< ulong2>  { typedef void type; }; 
#line 99
template<> struct __nv_itex_trait< ulong4>  { typedef void type; }; 
#line 101 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template<> struct __nv_itex_trait< float>  { typedef void type; }; 
#line 102
template<> struct __nv_itex_trait< float1>  { typedef void type; }; 
#line 103
template<> struct __nv_itex_trait< float2>  { typedef void type; }; 
#line 104
template<> struct __nv_itex_trait< float4>  { typedef void type; }; 
#line 108
template< class T> static typename __nv_itex_trait< T> ::type 
#line 109
tex1Dfetch(T *ptr, ::cudaTextureObject_t obj, int x) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;::exit(___);}
#if 0
#line 110
{ 
#line 111
__nv_tex_surf_handler("__itex1Dfetch", ptr, obj, x); 
#line 112
} 
#endif
#line 114 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 115
tex1Dfetch(::cudaTextureObject_t texObject, int x) {int volatile ___ = 1;(void)texObject;(void)x;::exit(___);}
#if 0
#line 116
{ 
#line 117
T ret; 
#line 118
tex1Dfetch(&ret, texObject, x); 
#line 119
return ret; 
#line 120
} 
#endif
#line 122 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 123
tex1D(T *ptr, ::cudaTextureObject_t obj, float x) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;::exit(___);}
#if 0
#line 124
{ 
#line 125
__nv_tex_surf_handler("__itex1D", ptr, obj, x); 
#line 126
} 
#endif
#line 129 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 130
tex1D(::cudaTextureObject_t texObject, float x) {int volatile ___ = 1;(void)texObject;(void)x;::exit(___);}
#if 0
#line 131
{ 
#line 132
T ret; 
#line 133
tex1D(&ret, texObject, x); 
#line 134
return ret; 
#line 135
} 
#endif
#line 138 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 139
tex2D(T *ptr, ::cudaTextureObject_t obj, float x, float y) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;::exit(___);}
#if 0
#line 140
{ 
#line 141
__nv_tex_surf_handler("__itex2D", ptr, obj, x, y); 
#line 142
} 
#endif
#line 144 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 145
tex2D(::cudaTextureObject_t texObject, float x, float y) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;::exit(___);}
#if 0
#line 146
{ 
#line 147
T ret; 
#line 148
tex2D(&ret, texObject, x, y); 
#line 149
return ret; 
#line 150
} 
#endif
#line 153 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 154
tex2D(T *ptr, ::cudaTextureObject_t obj, float x, float y, bool *
#line 155
isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;::exit(___);}
#if 0
#line 156
{ 
#line 157
unsigned char res; 
#line 158
__nv_tex_surf_handler("__itex2D_sparse", ptr, obj, x, y, &res); 
#line 159
(*isResident) = (res != 0); 
#line 160
} 
#endif
#line 162 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 163
tex2D(::cudaTextureObject_t texObject, float x, float y, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)isResident;::exit(___);}
#if 0
#line 164
{ 
#line 165
T ret; 
#line 166
tex2D(&ret, texObject, x, y, isResident); 
#line 167
return ret; 
#line 168
} 
#endif
#line 173 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 174
tex3D(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 175
{ 
#line 176
__nv_tex_surf_handler("__itex3D", ptr, obj, x, y, z); 
#line 177
} 
#endif
#line 179 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 180
tex3D(::cudaTextureObject_t texObject, float x, float y, float z) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 181
{ 
#line 182
T ret; 
#line 183
tex3D(&ret, texObject, x, y, z); 
#line 184
return ret; 
#line 185
} 
#endif
#line 188 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 189
tex3D(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, bool *
#line 190
isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)isResident;::exit(___);}
#if 0
#line 191
{ 
#line 192
unsigned char res; 
#line 193
__nv_tex_surf_handler("__itex3D_sparse", ptr, obj, x, y, z, &res); 
#line 194
(*isResident) = (res != 0); 
#line 195
} 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 198
tex3D(::cudaTextureObject_t texObject, float x, float y, float z, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)isResident;::exit(___);}
#if 0
#line 199
{ 
#line 200
T ret; 
#line 201
tex3D(&ret, texObject, x, y, z, isResident); 
#line 202
return ret; 
#line 203
} 
#endif
#line 207 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 208
tex1DLayered(T *ptr, ::cudaTextureObject_t obj, float x, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;::exit(___);}
#if 0
#line 209
{ 
#line 210
__nv_tex_surf_handler("__itex1DLayered", ptr, obj, x, layer); 
#line 211
} 
#endif
#line 213 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 214
tex1DLayered(::cudaTextureObject_t texObject, float x, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;::exit(___);}
#if 0
#line 215
{ 
#line 216
T ret; 
#line 217
tex1DLayered(&ret, texObject, x, layer); 
#line 218
return ret; 
#line 219
} 
#endif
#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 222
tex2DLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;::exit(___);}
#if 0
#line 223
{ 
#line 224
__nv_tex_surf_handler("__itex2DLayered", ptr, obj, x, y, layer); 
#line 225
} 
#endif
#line 227 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 228
tex2DLayered(::cudaTextureObject_t texObject, float x, float y, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;::exit(___);}
#if 0
#line 229
{ 
#line 230
T ret; 
#line 231
tex2DLayered(&ret, texObject, x, y, layer); 
#line 232
return ret; 
#line 233
} 
#endif
#line 236 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 237
tex2DLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)isResident;::exit(___);}
#if 0
#line 238
{ 
#line 239
unsigned char res; 
#line 240
__nv_tex_surf_handler("__itex2DLayered_sparse", ptr, obj, x, y, layer, &res); 
#line 241
(*isResident) = (res != 0); 
#line 242
} 
#endif
#line 244 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 245
tex2DLayered(::cudaTextureObject_t texObject, float x, float y, int layer, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)isResident;::exit(___);}
#if 0
#line 246
{ 
#line 247
T ret; 
#line 248
tex2DLayered(&ret, texObject, x, y, layer, isResident); 
#line 249
return ret; 
#line 250
} 
#endif
#line 254 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 255
texCubemap(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 256
{ 
#line 257
__nv_tex_surf_handler("__itexCubemap", ptr, obj, x, y, z); 
#line 258
} 
#endif
#line 261 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 262
texCubemap(::cudaTextureObject_t texObject, float x, float y, float z) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;::exit(___);}
#if 0
#line 263
{ 
#line 264
T ret; 
#line 265
texCubemap(&ret, texObject, x, y, z); 
#line 266
return ret; 
#line 267
} 
#endif
#line 270 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 271
texCubemapLayered(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;::exit(___);}
#if 0
#line 272
{ 
#line 273
__nv_tex_surf_handler("__itexCubemapLayered", ptr, obj, x, y, z, layer); 
#line 274
} 
#endif
#line 276 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 277
texCubemapLayered(::cudaTextureObject_t texObject, float x, float y, float z, int layer) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;::exit(___);}
#if 0
#line 278
{ 
#line 279
T ret; 
#line 280
texCubemapLayered(&ret, texObject, x, y, z, layer); 
#line 281
return ret; 
#line 282
} 
#endif
#line 284 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 285
tex2Dgather(T *ptr, ::cudaTextureObject_t obj, float x, float y, int comp = 0) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)comp;::exit(___);}
#if 0
#line 286
{ 
#line 287
__nv_tex_surf_handler("__itex2Dgather", ptr, obj, x, y, comp); 
#line 288
} 
#endif
#line 290 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 291
tex2Dgather(::cudaTextureObject_t to, float x, float y, int comp = 0) {int volatile ___ = 1;(void)to;(void)x;(void)y;(void)comp;::exit(___);}
#if 0
#line 292
{ 
#line 293
T ret; 
#line 294
tex2Dgather(&ret, to, x, y, comp); 
#line 295
return ret; 
#line 296
} 
#endif
#line 299 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 300
tex2Dgather(T *ptr, ::cudaTextureObject_t obj, float x, float y, bool *isResident, int comp = 0) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)isResident;(void)comp;::exit(___);}
#if 0
#line 301
{ 
#line 302
unsigned char res; 
#line 303
__nv_tex_surf_handler("__itex2Dgather_sparse", ptr, obj, x, y, comp, &res); 
#line 304
(*isResident) = (res != 0); 
#line 305
} 
#endif
#line 307 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 308
tex2Dgather(::cudaTextureObject_t to, float x, float y, bool *isResident, int comp = 0) {int volatile ___ = 1;(void)to;(void)x;(void)y;(void)isResident;(void)comp;::exit(___);}
#if 0
#line 309
{ 
#line 310
T ret; 
#line 311
tex2Dgather(&ret, to, x, y, isResident, comp); 
#line 312
return ret; 
#line 313
} 
#endif
#line 317 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 318
tex1DLod(T *ptr, ::cudaTextureObject_t obj, float x, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)level;::exit(___);}
#if 0
#line 319
{ 
#line 320
__nv_tex_surf_handler("__itex1DLod", ptr, obj, x, level); 
#line 321
} 
#endif
#line 323 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 324
tex1DLod(::cudaTextureObject_t texObject, float x, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)level;::exit(___);}
#if 0
#line 325
{ 
#line 326
T ret; 
#line 327
tex1DLod(&ret, texObject, x, level); 
#line 328
return ret; 
#line 329
} 
#endif
#line 332 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 333
tex2DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;::exit(___);}
#if 0
#line 334
{ 
#line 335
__nv_tex_surf_handler("__itex2DLod", ptr, obj, x, y, level); 
#line 336
} 
#endif
#line 338 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 339
tex2DLod(::cudaTextureObject_t texObject, float x, float y, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;::exit(___);}
#if 0
#line 340
{ 
#line 341
T ret; 
#line 342
tex2DLod(&ret, texObject, x, y, level); 
#line 343
return ret; 
#line 344
} 
#endif
#line 348 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 349
tex2DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)level;(void)isResident;::exit(___);}
#if 0
#line 350
{ 
#line 351
unsigned char res; 
#line 352
__nv_tex_surf_handler("__itex2DLod_sparse", ptr, obj, x, y, level, &res); 
#line 353
(*isResident) = (res != 0); 
#line 354
} 
#endif
#line 356 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 357
tex2DLod(::cudaTextureObject_t texObject, float x, float y, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)level;(void)isResident;::exit(___);}
#if 0
#line 358
{ 
#line 359
T ret; 
#line 360
tex2DLod(&ret, texObject, x, y, level, isResident); 
#line 361
return ret; 
#line 362
} 
#endif
#line 367 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 368
tex3DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 369
{ 
#line 370
__nv_tex_surf_handler("__itex3DLod", ptr, obj, x, y, z, level); 
#line 371
} 
#endif
#line 373 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 374
tex3DLod(::cudaTextureObject_t texObject, float x, float y, float z, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 375
{ 
#line 376
T ret; 
#line 377
tex3DLod(&ret, texObject, x, y, z, level); 
#line 378
return ret; 
#line 379
} 
#endif
#line 382 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 383
tex3DLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;(void)isResident;::exit(___);}
#if 0
#line 384
{ 
#line 385
unsigned char res; 
#line 386
__nv_tex_surf_handler("__itex3DLod_sparse", ptr, obj, x, y, z, level, &res); 
#line 387
(*isResident) = (res != 0); 
#line 388
} 
#endif
#line 390 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 391
tex3DLod(::cudaTextureObject_t texObject, float x, float y, float z, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;(void)isResident;::exit(___);}
#if 0
#line 392
{ 
#line 393
T ret; 
#line 394
tex3DLod(&ret, texObject, x, y, z, level, isResident); 
#line 395
return ret; 
#line 396
} 
#endif
#line 401 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 402
tex1DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)level;::exit(___);}
#if 0
#line 403
{ 
#line 404
__nv_tex_surf_handler("__itex1DLayeredLod", ptr, obj, x, layer, level); 
#line 405
} 
#endif
#line 407 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 408
tex1DLayeredLod(::cudaTextureObject_t texObject, float x, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)level;::exit(___);}
#if 0
#line 409
{ 
#line 410
T ret; 
#line 411
tex1DLayeredLod(&ret, texObject, x, layer, level); 
#line 412
return ret; 
#line 413
} 
#endif
#line 416 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 417
tex2DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;::exit(___);}
#if 0
#line 418
{ 
#line 419
__nv_tex_surf_handler("__itex2DLayeredLod", ptr, obj, x, y, layer, level); 
#line 420
} 
#endif
#line 422 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 423
tex2DLayeredLod(::cudaTextureObject_t texObject, float x, float y, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;::exit(___);}
#if 0
#line 424
{ 
#line 425
T ret; 
#line 426
tex2DLayeredLod(&ret, texObject, x, y, layer, level); 
#line 427
return ret; 
#line 428
} 
#endif
#line 431 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 432
tex2DLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, float level, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)level;(void)isResident;::exit(___);}
#if 0
#line 433
{ 
#line 434
unsigned char res; 
#line 435
__nv_tex_surf_handler("__itex2DLayeredLod_sparse", ptr, obj, x, y, layer, level, &res); 
#line 436
(*isResident) = (res != 0); 
#line 437
} 
#endif
#line 439 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 440
tex2DLayeredLod(::cudaTextureObject_t texObject, float x, float y, int layer, float level, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)level;(void)isResident;::exit(___);}
#if 0
#line 441
{ 
#line 442
T ret; 
#line 443
tex2DLayeredLod(&ret, texObject, x, y, layer, level, isResident); 
#line 444
return ret; 
#line 445
} 
#endif
#line 448 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 449
texCubemapLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 450
{ 
#line 451
__nv_tex_surf_handler("__itexCubemapLod", ptr, obj, x, y, z, level); 
#line 452
} 
#endif
#line 454 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 455
texCubemapLod(::cudaTextureObject_t texObject, float x, float y, float z, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)level;::exit(___);}
#if 0
#line 456
{ 
#line 457
T ret; 
#line 458
texCubemapLod(&ret, texObject, x, y, z, level); 
#line 459
return ret; 
#line 460
} 
#endif
#line 463 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 464
texCubemapGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 465
{ 
#line 466
__nv_tex_surf_handler("__itexCubemapGrad_v2", ptr, obj, x, y, z, &dPdx, &dPdy); 
#line 467
} 
#endif
#line 469 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 470
texCubemapGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 471
{ 
#line 472
T ret; 
#line 473
texCubemapGrad(&ret, texObject, x, y, z, dPdx, dPdy); 
#line 474
return ret; 
#line 475
} 
#endif
#line 477 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 478
texCubemapLayeredLod(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer, float level) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)level;::exit(___);}
#if 0
#line 479
{ 
#line 480
__nv_tex_surf_handler("__itexCubemapLayeredLod", ptr, obj, x, y, z, layer, level); 
#line 481
} 
#endif
#line 483 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 484
texCubemapLayeredLod(::cudaTextureObject_t texObject, float x, float y, float z, int layer, float level) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)level;::exit(___);}
#if 0
#line 485
{ 
#line 486
T ret; 
#line 487
texCubemapLayeredLod(&ret, texObject, x, y, z, layer, level); 
#line 488
return ret; 
#line 489
} 
#endif
#line 491 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 492
tex1DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float dPdx, float dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 493
{ 
#line 494
__nv_tex_surf_handler("__itex1DGrad", ptr, obj, x, dPdx, dPdy); 
#line 495
} 
#endif
#line 497 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 498
tex1DGrad(::cudaTextureObject_t texObject, float x, float dPdx, float dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 499
{ 
#line 500
T ret; 
#line 501
tex1DGrad(&ret, texObject, x, dPdx, dPdy); 
#line 502
return ret; 
#line 503
} 
#endif
#line 506 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 507
tex2DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 508
{ 
#line 509
__nv_tex_surf_handler("__itex2DGrad_v2", ptr, obj, x, y, &dPdx, &dPdy); 
#line 510
} 
#endif
#line 512 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 513
tex2DGrad(::cudaTextureObject_t texObject, float x, float y, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 514
{ 
#line 515
T ret; 
#line 516
tex2DGrad(&ret, texObject, x, y, dPdx, dPdy); 
#line 517
return ret; 
#line 518
} 
#endif
#line 521 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 522
tex2DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 523
{ 
#line 524
unsigned char res; 
#line 525
__nv_tex_surf_handler("__itex2DGrad_sparse", ptr, obj, x, y, &dPdx, &dPdy, &res); 
#line 526
(*isResident) = (res != 0); 
#line 527
} 
#endif
#line 529 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 530
tex2DGrad(::cudaTextureObject_t texObject, float x, float y, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 531
{ 
#line 532
T ret; 
#line 533
tex2DGrad(&ret, texObject, x, y, dPdx, dPdy, isResident); 
#line 534
return ret; 
#line 535
} 
#endif
#line 539 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 540
tex3DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 541
{ 
#line 542
__nv_tex_surf_handler("__itex3DGrad_v2", ptr, obj, x, y, z, &dPdx, &dPdy); 
#line 543
} 
#endif
#line 545 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 546
tex3DGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 547
{ 
#line 548
T ret; 
#line 549
tex3DGrad(&ret, texObject, x, y, z, dPdx, dPdy); 
#line 550
return ret; 
#line 551
} 
#endif
#line 554 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 555
tex3DGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, ::float4 dPdx, ::float4 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 556
{ 
#line 557
unsigned char res; 
#line 558
__nv_tex_surf_handler("__itex3DGrad_sparse", ptr, obj, x, y, z, &dPdx, &dPdy, &res); 
#line 559
(*isResident) = (res != 0); 
#line 560
} 
#endif
#line 562 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 563
tex3DGrad(::cudaTextureObject_t texObject, float x, float y, float z, ::float4 dPdx, ::float4 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 564
{ 
#line 565
T ret; 
#line 566
tex3DGrad(&ret, texObject, x, y, z, dPdx, dPdy, isResident); 
#line 567
return ret; 
#line 568
} 
#endif
#line 573 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 574
tex1DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, int layer, float dPdx, float dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 575
{ 
#line 576
__nv_tex_surf_handler("__itex1DLayeredGrad", ptr, obj, x, layer, dPdx, dPdy); 
#line 577
} 
#endif
#line 579 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 580
tex1DLayeredGrad(::cudaTextureObject_t texObject, float x, int layer, float dPdx, float dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 581
{ 
#line 582
T ret; 
#line 583
tex1DLayeredGrad(&ret, texObject, x, layer, dPdx, dPdy); 
#line 584
return ret; 
#line 585
} 
#endif
#line 588 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 589
tex2DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 590
{ 
#line 591
__nv_tex_surf_handler("__itex2DLayeredGrad_v2", ptr, obj, x, y, layer, &dPdx, &dPdy); 
#line 592
} 
#endif
#line 594 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 595
tex2DLayeredGrad(::cudaTextureObject_t texObject, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 596
{ 
#line 597
T ret; 
#line 598
tex2DLayeredGrad(&ret, texObject, x, y, layer, dPdx, dPdy); 
#line 599
return ret; 
#line 600
} 
#endif
#line 603 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 604
tex2DLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 605
{ 
#line 606
unsigned char res; 
#line 607
__nv_tex_surf_handler("__itex2DLayeredGrad_sparse", ptr, obj, x, y, layer, &dPdx, &dPdy, &res); 
#line 608
(*isResident) = (res != 0); 
#line 609
} 
#endif
#line 611 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 612
tex2DLayeredGrad(::cudaTextureObject_t texObject, float x, float y, int layer, ::float2 dPdx, ::float2 dPdy, bool *isResident) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)layer;(void)dPdx;(void)dPdy;(void)isResident;::exit(___);}
#if 0
#line 613
{ 
#line 614
T ret; 
#line 615
tex2DLayeredGrad(&ret, texObject, x, y, layer, dPdx, dPdy, isResident); 
#line 616
return ret; 
#line 617
} 
#endif
#line 621 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static typename __nv_itex_trait< T> ::type 
#line 622
texCubemapLayeredGrad(T *ptr, ::cudaTextureObject_t obj, float x, float y, float z, int layer, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 623
{ 
#line 624
__nv_tex_surf_handler("__itexCubemapLayeredGrad_v2", ptr, obj, x, y, z, layer, &dPdx, &dPdy); 
#line 625
} 
#endif
#line 627 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\texture_indirect_functions.h"
template< class T> static T 
#line 628
texCubemapLayeredGrad(::cudaTextureObject_t texObject, float x, float y, float z, int layer, ::float4 dPdx, ::float4 dPdy) {int volatile ___ = 1;(void)texObject;(void)x;(void)y;(void)z;(void)layer;(void)dPdx;(void)dPdy;::exit(___);}
#if 0
#line 629
{ 
#line 630
T ret; 
#line 631
texCubemapLayeredGrad(&ret, texObject, x, y, z, layer, dPdx, dPdy); 
#line 632
return ret; 
#line 633
} 
#endif
#line 58 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> struct __nv_isurf_trait { }; 
#line 59
template<> struct __nv_isurf_trait< char>  { typedef void type; }; 
#line 60
template<> struct __nv_isurf_trait< signed char>  { typedef void type; }; 
#line 61
template<> struct __nv_isurf_trait< char1>  { typedef void type; }; 
#line 62
template<> struct __nv_isurf_trait< unsigned char>  { typedef void type; }; 
#line 63
template<> struct __nv_isurf_trait< uchar1>  { typedef void type; }; 
#line 64
template<> struct __nv_isurf_trait< short>  { typedef void type; }; 
#line 65
template<> struct __nv_isurf_trait< short1>  { typedef void type; }; 
#line 66
template<> struct __nv_isurf_trait< unsigned short>  { typedef void type; }; 
#line 67
template<> struct __nv_isurf_trait< ushort1>  { typedef void type; }; 
#line 68
template<> struct __nv_isurf_trait< int>  { typedef void type; }; 
#line 69
template<> struct __nv_isurf_trait< int1>  { typedef void type; }; 
#line 70
template<> struct __nv_isurf_trait< unsigned>  { typedef void type; }; 
#line 71
template<> struct __nv_isurf_trait< uint1>  { typedef void type; }; 
#line 72
template<> struct __nv_isurf_trait< __int64>  { typedef void type; }; 
#line 73
template<> struct __nv_isurf_trait< longlong1>  { typedef void type; }; 
#line 74
template<> struct __nv_isurf_trait< unsigned __int64>  { typedef void type; }; 
#line 75
template<> struct __nv_isurf_trait< ulonglong1>  { typedef void type; }; 
#line 76
template<> struct __nv_isurf_trait< float>  { typedef void type; }; 
#line 77
template<> struct __nv_isurf_trait< float1>  { typedef void type; }; 
#line 79
template<> struct __nv_isurf_trait< char2>  { typedef void type; }; 
#line 80
template<> struct __nv_isurf_trait< uchar2>  { typedef void type; }; 
#line 81
template<> struct __nv_isurf_trait< short2>  { typedef void type; }; 
#line 82
template<> struct __nv_isurf_trait< ushort2>  { typedef void type; }; 
#line 83
template<> struct __nv_isurf_trait< int2>  { typedef void type; }; 
#line 84
template<> struct __nv_isurf_trait< uint2>  { typedef void type; }; 
#line 85
template<> struct __nv_isurf_trait< longlong2>  { typedef void type; }; 
#line 86
template<> struct __nv_isurf_trait< ulonglong2>  { typedef void type; }; 
#line 87
template<> struct __nv_isurf_trait< float2>  { typedef void type; }; 
#line 89
template<> struct __nv_isurf_trait< char4>  { typedef void type; }; 
#line 90
template<> struct __nv_isurf_trait< uchar4>  { typedef void type; }; 
#line 91
template<> struct __nv_isurf_trait< short4>  { typedef void type; }; 
#line 92
template<> struct __nv_isurf_trait< ushort4>  { typedef void type; }; 
#line 93
template<> struct __nv_isurf_trait< int4>  { typedef void type; }; 
#line 94
template<> struct __nv_isurf_trait< uint4>  { typedef void type; }; 
#line 95
template<> struct __nv_isurf_trait< float4>  { typedef void type; }; 
#line 98
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 99
surf1Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)mode;::exit(___);}
#if 0
#line 100
{ 
#line 101
__nv_tex_surf_handler("__isurf1Dread", ptr, obj, x, mode); 
#line 102
} 
#endif
#line 104 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 105
surf1Dread(::cudaSurfaceObject_t surfObject, int x, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)boundaryMode;::exit(___);}
#if 0
#line 106
{ 
#line 107
T ret; 
#line 108
surf1Dread(&ret, surfObject, x, boundaryMode); 
#line 109
return ret; 
#line 110
} 
#endif
#line 112 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 113
surf2Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)mode;::exit(___);}
#if 0
#line 114
{ 
#line 115
__nv_tex_surf_handler("__isurf2Dread", ptr, obj, x, y, mode); 
#line 116
} 
#endif
#line 118 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 119
surf2Dread(::cudaSurfaceObject_t surfObject, int x, int y, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)boundaryMode;::exit(___);}
#if 0
#line 120
{ 
#line 121
T ret; 
#line 122
surf2Dread(&ret, surfObject, x, y, boundaryMode); 
#line 123
return ret; 
#line 124
} 
#endif
#line 127 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 128
surf3Dread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int z, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)z;(void)mode;::exit(___);}
#if 0
#line 129
{ 
#line 130
__nv_tex_surf_handler("__isurf3Dread", ptr, obj, x, y, z, mode); 
#line 131
} 
#endif
#line 133 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 134
surf3Dread(::cudaSurfaceObject_t surfObject, int x, int y, int z, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)z;(void)boundaryMode;::exit(___);}
#if 0
#line 135
{ 
#line 136
T ret; 
#line 137
surf3Dread(&ret, surfObject, x, y, z, boundaryMode); 
#line 138
return ret; 
#line 139
} 
#endif
#line 141 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 142
surf1DLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)layer;(void)mode;::exit(___);}
#if 0
#line 143
{ 
#line 144
__nv_tex_surf_handler("__isurf1DLayeredread", ptr, obj, x, layer, mode); 
#line 145
} 
#endif
#line 147 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 148
surf1DLayeredread(::cudaSurfaceObject_t surfObject, int x, int layer, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)layer;(void)boundaryMode;::exit(___);}
#if 0
#line 149
{ 
#line 150
T ret; 
#line 151
surf1DLayeredread(&ret, surfObject, x, layer, boundaryMode); 
#line 152
return ret; 
#line 153
} 
#endif
#line 155 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 156
surf2DLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layer;(void)mode;::exit(___);}
#if 0
#line 157
{ 
#line 158
__nv_tex_surf_handler("__isurf2DLayeredread", ptr, obj, x, y, layer, mode); 
#line 159
} 
#endif
#line 161 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 162
surf2DLayeredread(::cudaSurfaceObject_t surfObject, int x, int y, int layer, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layer;(void)boundaryMode;::exit(___);}
#if 0
#line 163
{ 
#line 164
T ret; 
#line 165
surf2DLayeredread(&ret, surfObject, x, y, layer, boundaryMode); 
#line 166
return ret; 
#line 167
} 
#endif
#line 169 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 170
surfCubemapread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int face, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)face;(void)mode;::exit(___);}
#if 0
#line 171
{ 
#line 172
__nv_tex_surf_handler("__isurfCubemapread", ptr, obj, x, y, face, mode); 
#line 173
} 
#endif
#line 175 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 176
surfCubemapread(::cudaSurfaceObject_t surfObject, int x, int y, int face, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)face;(void)boundaryMode;::exit(___);}
#if 0
#line 177
{ 
#line 178
T ret; 
#line 179
surfCubemapread(&ret, surfObject, x, y, face, boundaryMode); 
#line 180
return ret; 
#line 181
} 
#endif
#line 183 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 184
surfCubemapLayeredread(T *ptr, ::cudaSurfaceObject_t obj, int x, int y, int layerface, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)ptr;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;::exit(___);}
#if 0
#line 185
{ 
#line 186
__nv_tex_surf_handler("__isurfCubemapLayeredread", ptr, obj, x, y, layerface, mode); 
#line 187
} 
#endif
#line 189 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static T 
#line 190
surfCubemapLayeredread(::cudaSurfaceObject_t surfObject, int x, int y, int layerface, ::cudaSurfaceBoundaryMode boundaryMode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)surfObject;(void)x;(void)y;(void)layerface;(void)boundaryMode;::exit(___);}
#if 0
#line 191
{ 
#line 192
T ret; 
#line 193
surfCubemapLayeredread(&ret, surfObject, x, y, layerface, boundaryMode); 
#line 194
return ret; 
#line 195
} 
#endif
#line 197 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 198
surf1Dwrite(T val, ::cudaSurfaceObject_t obj, int x, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)mode;::exit(___);}
#if 0
#line 199
{ 
#line 200
__nv_tex_surf_handler("__isurf1Dwrite_v2", &val, obj, x, mode); 
#line 201
} 
#endif
#line 203 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 204
surf2Dwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)mode;::exit(___);}
#if 0
#line 205
{ 
#line 206
__nv_tex_surf_handler("__isurf2Dwrite_v2", &val, obj, x, y, mode); 
#line 207
} 
#endif
#line 209 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 210
surf3Dwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int z, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)z;(void)mode;::exit(___);}
#if 0
#line 211
{ 
#line 212
__nv_tex_surf_handler("__isurf3Dwrite_v2", &val, obj, x, y, z, mode); 
#line 213
} 
#endif
#line 215 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 216
surf1DLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)layer;(void)mode;::exit(___);}
#if 0
#line 217
{ 
#line 218
__nv_tex_surf_handler("__isurf1DLayeredwrite_v2", &val, obj, x, layer, mode); 
#line 219
} 
#endif
#line 221 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 222
surf2DLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int layer, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layer;(void)mode;::exit(___);}
#if 0
#line 223
{ 
#line 224
__nv_tex_surf_handler("__isurf2DLayeredwrite_v2", &val, obj, x, y, layer, mode); 
#line 225
} 
#endif
#line 227 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 228
surfCubemapwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int face, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)face;(void)mode;::exit(___);}
#if 0
#line 229
{ 
#line 230
__nv_tex_surf_handler("__isurfCubemapwrite_v2", &val, obj, x, y, face, mode); 
#line 231
} 
#endif
#line 233 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\surface_indirect_functions.h"
template< class T> static typename __nv_isurf_trait< T> ::type 
#line 234
surfCubemapLayeredwrite(T val, ::cudaSurfaceObject_t obj, int x, int y, int layerface, ::cudaSurfaceBoundaryMode mode = cudaBoundaryModeTrap) {int volatile ___ = 1;(void)val;(void)obj;(void)x;(void)y;(void)layerface;(void)mode;::exit(___);}
#if 0
#line 235
{ 
#line 236
__nv_tex_surf_handler("__isurfCubemapLayeredwrite_v2", &val, obj, x, y, layerface, mode); 
#line 237
} 
#endif
#line 3634 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\crt/device_functions.h"
extern "C" unsigned __stdcall __cudaPushCallConfiguration(dim3 gridDim, dim3 blockDim, size_t sharedMem = 0, CUstream_st * stream = 0); 
#line 68 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_launch_parameters.h"
extern "C" {
#line 71 "C:\\Program Files\\NVIDIA GPU Computing Toolkit\\CUDA\\v12.0\\include\\device_launch_parameters.h"
extern const uint3 __device_builtin_variable_threadIdx; 
#line 72
extern const uint3 __device_builtin_variable_blockIdx; 
#line 73
extern const dim3 __device_builtin_variable_blockDim; 
#line 74
extern const dim3 __device_builtin_variable_gridDim; 
#line 75
extern const int __device_builtin_variable_warpSize; 
#line 80
}
#line 206 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 207
cudaLaunchKernel(const T *
#line 208
func, ::dim3 
#line 209
gridDim, ::dim3 
#line 210
blockDim, void **
#line 211
args, ::size_t 
#line 212
sharedMem = 0, ::cudaStream_t 
#line 213
stream = 0) 
#line 215
{ 
#line 216
return ::cudaLaunchKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
#line 217
} 
#line 340 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 341
cudaLaunchCooperativeKernel(const T *
#line 342
func, ::dim3 
#line 343
gridDim, ::dim3 
#line 344
blockDim, void **
#line 345
args, ::size_t 
#line 346
sharedMem = 0, ::cudaStream_t 
#line 347
stream = 0) 
#line 349
{ 
#line 350
return ::cudaLaunchCooperativeKernel((const void *)func, gridDim, blockDim, args, sharedMem, stream); 
#line 351
} 
#line 384
static __inline cudaError_t cudaEventCreate(cudaEvent_t *
#line 385
event, unsigned 
#line 386
flags) 
#line 388
{ 
#line 389
return ::cudaEventCreateWithFlags(event, flags); 
#line 390
} 
#line 428
static __inline cudaError_t cudaGraphInstantiate(cudaGraphExec_t *
#line 429
pGraphExec, cudaGraph_t 
#line 430
graph, cudaGraphNode_t *
#line 431
pErrorNode, char *
#line 432
pLogBuffer, size_t 
#line 433
bufferSize) 
#line 435
{ 
#line 436
(void)pErrorNode; 
#line 437
(void)pLogBuffer; 
#line 438
(void)bufferSize; 
#line 439
return ::cudaGraphInstantiate(pGraphExec, graph, 0); 
#line 440
} 
#line 499
static __inline cudaError_t cudaMallocHost(void **
#line 500
ptr, size_t 
#line 501
size, unsigned 
#line 502
flags) 
#line 504
{ 
#line 505
return ::cudaHostAlloc(ptr, size, flags); 
#line 506
} 
#line 508
template< class T> static __inline ::cudaError_t 
#line 509
cudaHostAlloc(T **
#line 510
ptr, ::size_t 
#line 511
size, unsigned 
#line 512
flags) 
#line 514
{ 
#line 515
return ::cudaHostAlloc((void **)((void *)ptr), size, flags); 
#line 516
} 
#line 518
template< class T> static __inline ::cudaError_t 
#line 519
cudaHostGetDevicePointer(T **
#line 520
pDevice, void *
#line 521
pHost, unsigned 
#line 522
flags) 
#line 524
{ 
#line 525
return ::cudaHostGetDevicePointer((void **)((void *)pDevice), pHost, flags); 
#line 526
} 
#line 628
template< class T> static __inline ::cudaError_t 
#line 629
cudaMallocManaged(T **
#line 630
devPtr, ::size_t 
#line 631
size, unsigned 
#line 632
flags = 1) 
#line 634
{ 
#line 635
return ::cudaMallocManaged((void **)((void *)devPtr), size, flags); 
#line 636
} 
#line 718
template< class T> static __inline ::cudaError_t 
#line 719
cudaStreamAttachMemAsync(::cudaStream_t 
#line 720
stream, T *
#line 721
devPtr, ::size_t 
#line 722
length = 0, unsigned 
#line 723
flags = 4) 
#line 725
{ 
#line 726
return ::cudaStreamAttachMemAsync(stream, (void *)devPtr, length, flags); 
#line 727
} 
#line 729
template< class T> __inline ::cudaError_t 
#line 730
cudaMalloc(T **
#line 731
devPtr, ::size_t 
#line 732
size) 
#line 734
{ 
#line 735
return ::cudaMalloc((void **)((void *)devPtr), size); 
#line 736
} 
#line 738
template< class T> static __inline ::cudaError_t 
#line 739
cudaMallocHost(T **
#line 740
ptr, ::size_t 
#line 741
size, unsigned 
#line 742
flags = 0) 
#line 744
{ 
#line 745
return cudaMallocHost((void **)((void *)ptr), size, flags); 
#line 746
} 
#line 748
template< class T> static __inline ::cudaError_t 
#line 749
cudaMallocPitch(T **
#line 750
devPtr, ::size_t *
#line 751
pitch, ::size_t 
#line 752
width, ::size_t 
#line 753
height) 
#line 755
{ 
#line 756
return ::cudaMallocPitch((void **)((void *)devPtr), pitch, width, height); 
#line 757
} 
#line 768
static __inline cudaError_t cudaMallocAsync(void **
#line 769
ptr, size_t 
#line 770
size, cudaMemPool_t 
#line 771
memPool, cudaStream_t 
#line 772
stream) 
#line 774
{ 
#line 775
return ::cudaMallocFromPoolAsync(ptr, size, memPool, stream); 
#line 776
} 
#line 778
template< class T> static __inline ::cudaError_t 
#line 779
cudaMallocAsync(T **
#line 780
ptr, ::size_t 
#line 781
size, ::cudaMemPool_t 
#line 782
memPool, ::cudaStream_t 
#line 783
stream) 
#line 785
{ 
#line 786
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
#line 787
} 
#line 789
template< class T> static __inline ::cudaError_t 
#line 790
cudaMallocAsync(T **
#line 791
ptr, ::size_t 
#line 792
size, ::cudaStream_t 
#line 793
stream) 
#line 795
{ 
#line 796
return ::cudaMallocAsync((void **)((void *)ptr), size, stream); 
#line 797
} 
#line 799
template< class T> static __inline ::cudaError_t 
#line 800
cudaMallocFromPoolAsync(T **
#line 801
ptr, ::size_t 
#line 802
size, ::cudaMemPool_t 
#line 803
memPool, ::cudaStream_t 
#line 804
stream) 
#line 806
{ 
#line 807
return ::cudaMallocFromPoolAsync((void **)((void *)ptr), size, memPool, stream); 
#line 808
} 
#line 847
template< class T> static __inline ::cudaError_t 
#line 848
cudaMemcpyToSymbol(const T &
#line 849
symbol, const void *
#line 850
src, ::size_t 
#line 851
count, ::size_t 
#line 852
offset = 0, ::cudaMemcpyKind 
#line 853
kind = cudaMemcpyHostToDevice) 
#line 855
{ 
#line 856
return ::cudaMemcpyToSymbol((const void *)(&symbol), src, count, offset, kind); 
#line 857
} 
#line 901
template< class T> static __inline ::cudaError_t 
#line 902
cudaMemcpyToSymbolAsync(const T &
#line 903
symbol, const void *
#line 904
src, ::size_t 
#line 905
count, ::size_t 
#line 906
offset = 0, ::cudaMemcpyKind 
#line 907
kind = cudaMemcpyHostToDevice, ::cudaStream_t 
#line 908
stream = 0) 
#line 910
{ 
#line 911
return ::cudaMemcpyToSymbolAsync((const void *)(&symbol), src, count, offset, kind, stream); 
#line 912
} 
#line 949
template< class T> static __inline ::cudaError_t 
#line 950
cudaMemcpyFromSymbol(void *
#line 951
dst, const T &
#line 952
symbol, ::size_t 
#line 953
count, ::size_t 
#line 954
offset = 0, ::cudaMemcpyKind 
#line 955
kind = cudaMemcpyDeviceToHost) 
#line 957
{ 
#line 958
return ::cudaMemcpyFromSymbol(dst, (const void *)(&symbol), count, offset, kind); 
#line 959
} 
#line 1003
template< class T> static __inline ::cudaError_t 
#line 1004
cudaMemcpyFromSymbolAsync(void *
#line 1005
dst, const T &
#line 1006
symbol, ::size_t 
#line 1007
count, ::size_t 
#line 1008
offset = 0, ::cudaMemcpyKind 
#line 1009
kind = cudaMemcpyDeviceToHost, ::cudaStream_t 
#line 1010
stream = 0) 
#line 1012
{ 
#line 1013
return ::cudaMemcpyFromSymbolAsync(dst, (const void *)(&symbol), count, offset, kind, stream); 
#line 1014
} 
#line 1072
template< class T> static __inline ::cudaError_t 
#line 1073
cudaGraphAddMemcpyNodeToSymbol(::cudaGraphNode_t *
#line 1074
pGraphNode, ::cudaGraph_t 
#line 1075
graph, const ::cudaGraphNode_t *
#line 1076
pDependencies, ::size_t 
#line 1077
numDependencies, const T &
#line 1078
symbol, const void *
#line 1079
src, ::size_t 
#line 1080
count, ::size_t 
#line 1081
offset, ::cudaMemcpyKind 
#line 1082
kind) 
#line 1083
{ 
#line 1084
return ::cudaGraphAddMemcpyNodeToSymbol(pGraphNode, graph, pDependencies, numDependencies, (const void *)(&symbol), src, count, offset, kind); 
#line 1085
} 
#line 1143
template< class T> static __inline ::cudaError_t 
#line 1144
cudaGraphAddMemcpyNodeFromSymbol(::cudaGraphNode_t *
#line 1145
pGraphNode, ::cudaGraph_t 
#line 1146
graph, const ::cudaGraphNode_t *
#line 1147
pDependencies, ::size_t 
#line 1148
numDependencies, void *
#line 1149
dst, const T &
#line 1150
symbol, ::size_t 
#line 1151
count, ::size_t 
#line 1152
offset, ::cudaMemcpyKind 
#line 1153
kind) 
#line 1154
{ 
#line 1155
return ::cudaGraphAddMemcpyNodeFromSymbol(pGraphNode, graph, pDependencies, numDependencies, dst, (const void *)(&symbol), count, offset, kind); 
#line 1156
} 
#line 1194
template< class T> static __inline ::cudaError_t 
#line 1195
cudaGraphMemcpyNodeSetParamsToSymbol(::cudaGraphNode_t 
#line 1196
node, const T &
#line 1197
symbol, const void *
#line 1198
src, ::size_t 
#line 1199
count, ::size_t 
#line 1200
offset, ::cudaMemcpyKind 
#line 1201
kind) 
#line 1202
{ 
#line 1203
return ::cudaGraphMemcpyNodeSetParamsToSymbol(node, (const void *)(&symbol), src, count, offset, kind); 
#line 1204
} 
#line 1242
template< class T> static __inline ::cudaError_t 
#line 1243
cudaGraphMemcpyNodeSetParamsFromSymbol(::cudaGraphNode_t 
#line 1244
node, void *
#line 1245
dst, const T &
#line 1246
symbol, ::size_t 
#line 1247
count, ::size_t 
#line 1248
offset, ::cudaMemcpyKind 
#line 1249
kind) 
#line 1250
{ 
#line 1251
return ::cudaGraphMemcpyNodeSetParamsFromSymbol(node, dst, (const void *)(&symbol), count, offset, kind); 
#line 1252
} 
#line 1300
template< class T> static __inline ::cudaError_t 
#line 1301
cudaGraphExecMemcpyNodeSetParamsToSymbol(::cudaGraphExec_t 
#line 1302
hGraphExec, ::cudaGraphNode_t 
#line 1303
node, const T &
#line 1304
symbol, const void *
#line 1305
src, ::size_t 
#line 1306
count, ::size_t 
#line 1307
offset, ::cudaMemcpyKind 
#line 1308
kind) 
#line 1309
{ 
#line 1310
return ::cudaGraphExecMemcpyNodeSetParamsToSymbol(hGraphExec, node, (const void *)(&symbol), src, count, offset, kind); 
#line 1311
} 
#line 1359
template< class T> static __inline ::cudaError_t 
#line 1360
cudaGraphExecMemcpyNodeSetParamsFromSymbol(::cudaGraphExec_t 
#line 1361
hGraphExec, ::cudaGraphNode_t 
#line 1362
node, void *
#line 1363
dst, const T &
#line 1364
symbol, ::size_t 
#line 1365
count, ::size_t 
#line 1366
offset, ::cudaMemcpyKind 
#line 1367
kind) 
#line 1368
{ 
#line 1369
return ::cudaGraphExecMemcpyNodeSetParamsFromSymbol(hGraphExec, node, dst, (const void *)(&symbol), count, offset, kind); 
#line 1370
} 
#line 1373
static __inline cudaError_t __stdcall cudaGraphExecUpdate(cudaGraphExec_t hGraphExec, cudaGraph_t hGraph, cudaGraphNode_t *hErrorNode_out, cudaGraphExecUpdateResult *updateResult_out) 
#line 1374
{ 
#line 1375
cudaGraphExecUpdateResultInfo resultInfo; 
#line 1376
cudaError_t status = cudaGraphExecUpdate(hGraphExec, hGraph, &resultInfo); 
#line 1377
if (hErrorNode_out) { 
#line 1378
(*hErrorNode_out) = (resultInfo.errorNode); 
#line 1379
}  
#line 1380
if (updateResult_out) { 
#line 1381
(*updateResult_out) = (resultInfo.result); 
#line 1382
}  
#line 1383
return status; 
#line 1384
} 
#line 1462 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
template< class T> static __inline ::cudaError_t 
#line 1463
cudaGetSymbolAddress(void **
#line 1464
devPtr, const T &
#line 1465
symbol) 
#line 1467
{ 
#line 1468
return ::cudaGetSymbolAddress(devPtr, (const void *)(&symbol)); 
#line 1469
} 
#line 1494
template< class T> static __inline ::cudaError_t 
#line 1495
cudaGetSymbolSize(::size_t *
#line 1496
size, const T &
#line 1497
symbol) 
#line 1499
{ 
#line 1500
return ::cudaGetSymbolSize(size, (const void *)(&symbol)); 
#line 1501
} 
#line 1546
template< class T> static __inline ::cudaError_t 
#line 1547
cudaFuncSetCacheConfig(T *
#line 1548
func, ::cudaFuncCache 
#line 1549
cacheConfig) 
#line 1551
{ 
#line 1552
return ::cudaFuncSetCacheConfig((const void *)func, cacheConfig); 
#line 1553
} 
#line 1555
template< class T> static __inline ::cudaError_t 
#line 1556
cudaFuncSetSharedMemConfig(T *
#line 1557
func, ::cudaSharedMemConfig 
#line 1558
config) 
#line 1560
{ 
#line 1561
return ::cudaFuncSetSharedMemConfig((const void *)func, config); 
#line 1562
} 
#line 1594 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
template< class T> __inline ::cudaError_t 
#line 1595
cudaOccupancyMaxActiveBlocksPerMultiprocessor(int *
#line 1596
numBlocks, T 
#line 1597
func, int 
#line 1598
blockSize, ::size_t 
#line 1599
dynamicSMemSize) 
#line 1600
{ 
#line 1601
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, 0); 
#line 1602
} 
#line 1646
template< class T> __inline ::cudaError_t 
#line 1647
cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *
#line 1648
numBlocks, T 
#line 1649
func, int 
#line 1650
blockSize, ::size_t 
#line 1651
dynamicSMemSize, unsigned 
#line 1652
flags) 
#line 1653
{ 
#line 1654
return ::cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(numBlocks, (const void *)func, blockSize, dynamicSMemSize, flags); 
#line 1655
} 
#line 1660
class __cudaOccupancyB2DHelper { 
#line 1661
size_t n; 
#line 1663
public: __cudaOccupancyB2DHelper(size_t n_) : n(n_) { } 
#line 1664
size_t operator()(int) 
#line 1665
{ 
#line 1666
return n; 
#line 1667
} 
#line 1668
}; 
#line 1716
template< class UnaryFunction, class T> static __inline ::cudaError_t 
#line 1717
cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(int *
#line 1718
minGridSize, int *
#line 1719
blockSize, T 
#line 1720
func, UnaryFunction 
#line 1721
blockSizeToDynamicSMemSize, int 
#line 1722
blockSizeLimit = 0, unsigned 
#line 1723
flags = 0) 
#line 1724
{ 
#line 1725
::cudaError_t status; 
#line 1728
int device; 
#line 1729
::cudaFuncAttributes attr; 
#line 1732
int maxThreadsPerMultiProcessor; 
#line 1733
int warpSize; 
#line 1734
int devMaxThreadsPerBlock; 
#line 1735
int multiProcessorCount; 
#line 1736
int funcMaxThreadsPerBlock; 
#line 1737
int occupancyLimit; 
#line 1738
int granularity; 
#line 1741
int maxBlockSize = 0; 
#line 1742
int numBlocks = 0; 
#line 1743
int maxOccupancy = 0; 
#line 1746
int blockSizeToTryAligned; 
#line 1747
int blockSizeToTry; 
#line 1748
int blockSizeLimitAligned; 
#line 1749
int occupancyInBlocks; 
#line 1750
int occupancyInThreads; 
#line 1751
::size_t dynamicSMemSize; 
#line 1757
if (((!minGridSize) || (!blockSize)) || (!func)) { 
#line 1758
return cudaErrorInvalidValue; 
#line 1759
}  
#line 1765
status = ::cudaGetDevice(&device); 
#line 1766
if (status != (cudaSuccess)) { 
#line 1767
return status; 
#line 1768
}  
#line 1770
status = cudaDeviceGetAttribute(&maxThreadsPerMultiProcessor, cudaDevAttrMaxThreadsPerMultiProcessor, device); 
#line 1774
if (status != (cudaSuccess)) { 
#line 1775
return status; 
#line 1776
}  
#line 1778
status = cudaDeviceGetAttribute(&warpSize, cudaDevAttrWarpSize, device); 
#line 1782
if (status != (cudaSuccess)) { 
#line 1783
return status; 
#line 1784
}  
#line 1786
status = cudaDeviceGetAttribute(&devMaxThreadsPerBlock, cudaDevAttrMaxThreadsPerBlock, device); 
#line 1790
if (status != (cudaSuccess)) { 
#line 1791
return status; 
#line 1792
}  
#line 1794
status = cudaDeviceGetAttribute(&multiProcessorCount, cudaDevAttrMultiProcessorCount, device); 
#line 1798
if (status != (cudaSuccess)) { 
#line 1799
return status; 
#line 1800
}  
#line 1802
status = cudaFuncGetAttributes(&attr, func); 
#line 1803
if (status != (cudaSuccess)) { 
#line 1804
return status; 
#line 1805
}  
#line 1807
funcMaxThreadsPerBlock = (attr.maxThreadsPerBlock); 
#line 1813
occupancyLimit = maxThreadsPerMultiProcessor; 
#line 1814
granularity = warpSize; 
#line 1816
if (blockSizeLimit == 0) { 
#line 1817
blockSizeLimit = devMaxThreadsPerBlock; 
#line 1818
}  
#line 1820
if (devMaxThreadsPerBlock < blockSizeLimit) { 
#line 1821
blockSizeLimit = devMaxThreadsPerBlock; 
#line 1822
}  
#line 1824
if (funcMaxThreadsPerBlock < blockSizeLimit) { 
#line 1825
blockSizeLimit = funcMaxThreadsPerBlock; 
#line 1826
}  
#line 1828
blockSizeLimitAligned = (((blockSizeLimit + (granularity - 1)) / granularity) * granularity); 
#line 1830
for (blockSizeToTryAligned = blockSizeLimitAligned; blockSizeToTryAligned > 0; blockSizeToTryAligned -= granularity) { 
#line 1834
if (blockSizeLimit < blockSizeToTryAligned) { 
#line 1835
blockSizeToTry = blockSizeLimit; 
#line 1836
} else { 
#line 1837
blockSizeToTry = blockSizeToTryAligned; 
#line 1838
}  
#line 1840
dynamicSMemSize = blockSizeToDynamicSMemSize(blockSizeToTry); 
#line 1842
status = cudaOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(&occupancyInBlocks, func, blockSizeToTry, dynamicSMemSize, flags); 
#line 1849
if (status != (cudaSuccess)) { 
#line 1850
return status; 
#line 1851
}  
#line 1853
occupancyInThreads = (blockSizeToTry * occupancyInBlocks); 
#line 1855
if (occupancyInThreads > maxOccupancy) { 
#line 1856
maxBlockSize = blockSizeToTry; 
#line 1857
numBlocks = occupancyInBlocks; 
#line 1858
maxOccupancy = occupancyInThreads; 
#line 1859
}  
#line 1863
if (occupancyLimit == maxOccupancy) { 
#line 1864
break; 
#line 1865
}  
#line 1866
}  
#line 1874
(*minGridSize) = (numBlocks * multiProcessorCount); 
#line 1875
(*blockSize) = maxBlockSize; 
#line 1877
return status; 
#line 1878
} 
#line 1912
template< class UnaryFunction, class T> static __inline ::cudaError_t 
#line 1913
cudaOccupancyMaxPotentialBlockSizeVariableSMem(int *
#line 1914
minGridSize, int *
#line 1915
blockSize, T 
#line 1916
func, UnaryFunction 
#line 1917
blockSizeToDynamicSMemSize, int 
#line 1918
blockSizeLimit = 0) 
#line 1919
{ 
#line 1920
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, blockSizeLimit, 0); 
#line 1921
} 
#line 1958
template< class T> static __inline ::cudaError_t 
#line 1959
cudaOccupancyMaxPotentialBlockSize(int *
#line 1960
minGridSize, int *
#line 1961
blockSize, T 
#line 1962
func, ::size_t 
#line 1963
dynamicSMemSize = 0, int 
#line 1964
blockSizeLimit = 0) 
#line 1965
{ 
#line 1966
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((::__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, 0); 
#line 1967
} 
#line 1996
template< class T> static __inline ::cudaError_t 
#line 1997
cudaOccupancyAvailableDynamicSMemPerBlock(::size_t *
#line 1998
dynamicSmemSize, T 
#line 1999
func, int 
#line 2000
numBlocks, int 
#line 2001
blockSize) 
#line 2002
{ 
#line 2003
return ::cudaOccupancyAvailableDynamicSMemPerBlock(dynamicSmemSize, (const void *)func, numBlocks, blockSize); 
#line 2004
} 
#line 2055
template< class T> static __inline ::cudaError_t 
#line 2056
cudaOccupancyMaxPotentialBlockSizeWithFlags(int *
#line 2057
minGridSize, int *
#line 2058
blockSize, T 
#line 2059
func, ::size_t 
#line 2060
dynamicSMemSize = 0, int 
#line 2061
blockSizeLimit = 0, unsigned 
#line 2062
flags = 0) 
#line 2063
{ 
#line 2064
return cudaOccupancyMaxPotentialBlockSizeVariableSMemWithFlags(minGridSize, blockSize, func, ((::__cudaOccupancyB2DHelper)(dynamicSMemSize)), blockSizeLimit, flags); 
#line 2065
} 
#line 2099
template< class T> static __inline ::cudaError_t 
#line 2100
cudaOccupancyMaxPotentialClusterSize(int *
#line 2101
clusterSize, T *
#line 2102
func, const ::cudaLaunchConfig_t *
#line 2103
config) 
#line 2104
{ 
#line 2105
return ::cudaOccupancyMaxPotentialClusterSize(clusterSize, (const void *)func, config); 
#line 2106
} 
#line 2142
template< class T> static __inline ::cudaError_t 
#line 2143
cudaOccupancyMaxActiveClusters(int *
#line 2144
numClusters, T *
#line 2145
func, const ::cudaLaunchConfig_t *
#line 2146
config) 
#line 2147
{ 
#line 2148
return ::cudaOccupancyMaxActiveClusters(numClusters, (const void *)func, config); 
#line 2149
} 
#line 2182
template< class T> __inline ::cudaError_t 
#line 2183
cudaFuncGetAttributes(::cudaFuncAttributes *
#line 2184
attr, T *
#line 2185
entry) 
#line 2187
{ 
#line 2188
return ::cudaFuncGetAttributes(attr, (const void *)entry); 
#line 2189
} 
#line 2244
template< class T> static __inline ::cudaError_t 
#line 2245
cudaFuncSetAttribute(T *
#line 2246
entry, ::cudaFuncAttribute 
#line 2247
attr, int 
#line 2248
value) 
#line 2250
{ 
#line 2251
return ::cudaFuncSetAttribute((const void *)entry, attr, value); 
#line 2252
} 
#line 2266 "C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.0/bin/../include\\cuda_runtime.h"
#pragma warning(pop)
#line 64 "CMakeCUDACompilerId.cu"
const char *info_compiler = ("INFO:compiler[NVIDIA]"); 
#line 66
const char *info_simulate = ("INFO:simulate[MSVC]"); 
#line 369 "CMakeCUDACompilerId.cu"
const char info_version[] = {'I', 'N', 'F', 'O', ':', 'c', 'o', 'm', 'p', 'i', 'l', 'e', 'r', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + ((12 / 10000000) % 10)), (('0') + ((12 / 1000000) % 10)), (('0') + ((12 / 100000) % 10)), (('0') + ((12 / 10000) % 10)), (('0') + ((12 / 1000) % 10)), (('0') + ((12 / 100) % 10)), (('0') + ((12 / 10) % 10)), (('0') + (12 % 10)), '.', (('0') + ((0 / 10000000) % 10)), (('0') + ((0 / 1000000) % 10)), (('0') + ((0 / 100000) % 10)), (('0') + ((0 / 10000) % 10)), (('0') + ((0 / 1000) % 10)), (('0') + ((0 / 100) % 10)), (('0') + ((0 / 10) % 10)), (('0') + (0 % 10)), '.', (('0') + ((140 / 10000000) % 10)), (('0') + ((140 / 1000000) % 10)), (('0') + ((140 / 100000) % 10)), (('0') + ((140 / 10000) % 10)), (('0') + ((140 / 1000) % 10)), (('0') + ((140 / 100) % 10)), (('0') + ((140 / 10) % 10)), (('0') + (140 % 10)), ']', '\000'}; 
#line 398 "CMakeCUDACompilerId.cu"
const char info_simulate_version[] = {'I', 'N', 'F', 'O', ':', 's', 'i', 'm', 'u', 'l', 'a', 't', 'e', '_', 'v', 'e', 'r', 's', 'i', 'o', 'n', '[', (('0') + (((1936 / 100) / 10000000) % 10)), (('0') + (((1936 / 100) / 1000000) % 10)), (('0') + (((1936 / 100) / 100000) % 10)), (('0') + (((1936 / 100) / 10000) % 10)), (('0') + (((1936 / 100) / 1000) % 10)), (('0') + (((1936 / 100) / 100) % 10)), (('0') + (((1936 / 100) / 10) % 10)), (('0') + ((1936 / 100) % 10)), '.', (('0') + (((1936 % 100) / 10000000) % 10)), (('0') + (((1936 % 100) / 1000000) % 10)), (('0') + (((1936 % 100) / 100000) % 10)), (('0') + (((1936 % 100) / 10000) % 10)), (('0') + (((1936 % 100) / 1000) % 10)), (('0') + (((1936 % 100) / 100) % 10)), (('0') + (((1936 % 100) / 10) % 10)), (('0') + ((1936 % 100) % 10)), ']', '\000'}; 
#line 418 "CMakeCUDACompilerId.cu"
const char *info_platform = ("INFO:platform[Windows]"); 
#line 419
const char *info_arch = ("INFO:arch[x64]"); 
#line 423
const char *info_language_standard_default = ("INFO:standard_default[03]"); 
#line 439 "CMakeCUDACompilerId.cu"
const char *info_language_extensions_default = ("INFO:extensions_default[OFF]"); 
#line 450 "CMakeCUDACompilerId.cu"
int main(int argc, char *argv[]) 
#line 451
{ 
#line 452
int require = 0; 
#line 453
require += (info_compiler[argc]); 
#line 454
require += (info_platform[argc]); 
#line 456
require += (info_version[argc]); 
#line 459 "CMakeCUDACompilerId.cu"
require += (info_simulate[argc]); 
#line 462 "CMakeCUDACompilerId.cu"
require += (info_simulate_version[argc]); 
#line 464 "CMakeCUDACompilerId.cu"
require += (info_language_standard_default[argc]); 
#line 465
require += (info_language_extensions_default[argc]); 
#line 466
(void)argv; 
#line 467
return require; 
#line 468
} 
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#define _NV_ANON_NAMESPACE _GLOBAL__N__673c45ee_22_CMakeCUDACompilerId_cu_bd57c623
#ifdef _NV_ANON_NAMESPACE
#endif
#pragma pack()
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#include "CMakeCUDACompilerId.cudafe1.stub.c"
#line 1 "CMakeCUDACompilerId.cudafe1.stub.c"
#undef _NV_ANON_NAMESPACE

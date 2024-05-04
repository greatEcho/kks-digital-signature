// initial parameters
#define PARAM_N 3900
#define PARAM_K 3050
#define PARAM_n 356
#define PARAM_k 256
#define t1 149
#define t2 207

#define SIZE_H (uint32_t)( (PARAM_N - PARAM_K) * PARAM_N )
#define SIZE_G (uint32_t)( PARAM_k * PARAM_n )
#define SIZE_H_J (uint32_t)( (PARAM_N - PARAM_K) * PARAM_n )
#define BYTES_k ( (PARAM_k+7) / 8)
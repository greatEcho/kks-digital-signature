#include "../src/include.h"


void random_matrix(byte matrice[], uint32_t size);
void print_matrice(byte matrice[], uint32_t size);
uint32_t tobytes(uint32_t value);
uint32_t generate_random_up_to_N();
void initialize_J(byte *J);
void matrix_multiply(const byte *A, matrix_size size_A,
                     const byte *B, matrix_size size_B,
                     byte *C, bool to_transpose, 
                     bool via_J, const byte *J);
byte compute_element(size_t row, size_t col, 
                     const byte *A, matrix_size size_A,
                     const byte *B, matrix_size size_B, bool to_transpose);
byte compute_element_via_J(size_t row, size_t col,
                           const byte *A, matrix_size size_A,
                           const byte *B, matrix_size size_B, const byte *J);
byte product_cell(byte one_byte);


void matrix_multiplication(byte *A, matrix_size size_A, 
                           byte *B, matrix_size size_B,
                           byte *C, matrix_size size_C);
void print_matrice_pretty(byte matrice[], matrix_size size);
void compute_sha256(const char* str, unsigned char* output);
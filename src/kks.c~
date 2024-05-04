#include "include.h"





//const uint16_t N = 3900, K = 3050, 
               //n = 80, k = 256, 
               //t1 = 26, t2 = 54;

int main(int argc, char* argv[])
{

    printf("%i\n", SIZE_H);
    printf("Let the Sender's name be Bob\n"
           "and the Receiver's name be Alice\n");

    // generate random parity-check matrix H
    byte matrice_H[SIZE_H]; 
    random_matrix(matrice_H, SIZE_H);
    printf("Bob generates random parity-check matrix H (general public key)..\n");
    //print_matrice_pretty(matrice_H, (matrix_size){.rows=PARAM_N-PARAM_K, .cols=PARAM_N});

    // random subset J of {1,..N} of cardinality n
    byte J[PARAM_N];
    initialize_J(J);
    printf("\n");
    printf("Bob generates set J - randomly choose n columns in H (secret key)..\n");
    //print_matrice(J, PARAM_N);
    //print_matrice_pretty(J, (matrix_size){1, PARAM_N});
    printf("\n");

    // random generator matrix G
    byte matrice_G[SIZE_G];
    random_matrix(matrice_G, SIZE_G);
    printf("Bob generates random generator matrix G (general secret key)..\n");
    //print_matrice_pretty(matrice_G, (matrix_size){.rows=PARAM_k, .cols=PARAM_n});

    // F matrix

    byte matrice_F[(PARAM_N-PARAM_K) * PARAM_k];
    matrix_multiply(matrice_H, (matrix_size){PARAM_N-PARAM_K, PARAM_N},
                    matrice_G, (matrix_size){PARAM_k, PARAM_n},
                    matrice_F, true, true, J);
    printf("Bob constructs public key F..\n");
    //print_matrice_pretty(matrice_F, (matrix_size){PARAM_N-PARAM_K, PARAM_k});

    // get the hash of random message
    byte message[PARAM_N];
    random_matrix(message, PARAM_N);
    byte hash[PARAM_k];
    compute_sha256(message, hash);
    printf("SHA-256 of\n");
    print_matrice(message, PARAM_N);
    printf("\nis:");
    for (size_t i=0; i<BYTES_k; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

#if 0
    convert_to_binary(hash, PARAM_k, BYTES_k);
void convert_to_binary(byte vector, uint32_t size_bits, uint16_t size_bytes)
{
    uint32_t i;
    for (i=size_bytes-1; i>0; i--) {
        for (size_t j=0; j<BYTE; j++) {
        }
#endif


#if 0
    byte C[((PARAM_N-PARAM_K) * 1)];
    matrix_multiply(matrice_H, (matrix_size){PARAM_N-PARAM_K, PARAM_N},
                   J, (matrix_size){5, 2}, C,
                   false, false, 0); 
    //printf("\n");
    //print_matrice(C, (PARAM_N-PARAM_K) * 1);
    print_matrice_pretty(C, (matrix_size){2, 2});
#endif

    return 0;
}


void print_matrice(byte matrice[], uint32_t size)
{
    for (size_t i=0; i<size; i++) {
        printf("%b ", matrice[i]);
    }
    printf("\n");
}

void print_matrice_pretty(byte matrice[], matrix_size size)
{
    for (size_t i=0; i<size.rows; i++) {
        for (size_t j=0; j<size.cols; j++) {
            printf("%b ", matrice[i*size.cols + j]);
        }
        printf("\n");
    }
}

uint32_t tobytes(uint32_t value)
{
    uint32_t in_bytes;
    if (!(value % 8))
        in_bytes = value / 8;
    else 
        in_bytes = value / 8 + 1;

    return in_bytes;
}

void initialize_J(byte *J)
{
    memset(J, 0, PARAM_N*sizeof(byte));
    uint16_t n = PARAM_n;
    while(n) {
        size_t k = generate_random_up_to_N();
        if (J[k] == 0) {
            J[k] = 1;
            n--;
        }
    }
}

#define NUMBER (PARAM_N+1)
uint32_t generate_random_up_to_N()
{
    // 2^16, as we're combining two bytes
    uint32_t range = 65536; 
    // Find the largest multiple of 3001 less than 65536
    uint32_t cutoff = range - (range % NUMBER); 
    uint32_t result;

    do {
        // Get the first byte
        result = random_byte();       

        // Add the second byte to form a 16-bit number
        result = (result << 8) | random_byte(); 
                                                //
    // Repeat if the number is in the range we're discarding
    } while (result >= cutoff); 

    // The result is uniformly distributed in [0, 3000]
    return result % NUMBER; 
}

byte product_cell(byte one_byte)
{
    size_t result = 0;
    for (size_t i=0; i<8;i++) {
        result ^= (one_byte >> i) & 1;
    }
    return result;
}

#if 0
void matrix_multiplication(byte *A, matrix_size size_A, 
                           byte *B, matrix_size size_B,
                           byte *C, matrix_size size_C)
{

    for (size_t i=0;i<size_C.rows; i++) {
        for (size_t j=0;j<size_C.cols; j++) {
            C[(size_C.rows-1)*i + j] = A[i] ^ B[j];
        }
    }

    byte byte_i;
    for (size_t i=0; i<size_C.rows; i++) {
        for (size_t j=0; j<size_C.cols; j++) {
            byte_i = 0x0;
            for (size_t bit_i=BYTE-1; bit_i>=0; bit_i--) {
                for 
                C[(size_C.rows-1)
}
#endif

void matrix_multiply(const byte *A, matrix_size size_A,
                     const byte *B, matrix_size size_B,
                     byte *C, bool to_transpose,
                     bool via_J, const byte *J)
{
    size_t i,j;
    for (i=0; i<size_A.rows; i++) {
        if (to_transpose) {
            // size_B.rows because we store B in not transposed form
            for (j = 0; j < size_B.rows; j++)
            {
                if (via_J)
                    C[size_B.rows * i + j] = compute_element_via_J(i, j, A, size_A, B, size_B, J);
                else
                    C[size_B.rows * i + j] = compute_element(i, j, A, size_A, B, size_B, to_transpose);
            }
        }
        else {
            // we will go column by column for each row of A
            for (j = 0; j < size_B.cols; j++)
            {
                if (via_J)
                    C[size_B.cols * i + j] = compute_element_via_J(i, j, A, size_A, B, size_B, J);
                else
                    C[size_B.cols * i + j] = compute_element(i, j, A, size_A, B, size_B, to_transpose);
            }

        }
    }
}

byte compute_element(size_t row, size_t col, 
                     const byte *A, matrix_size size_A,
                     const byte *B, matrix_size size_B, bool to_transpose)
{
    size_t i;
    byte addend, element = 0;
    for (i=0; i<size_A.cols; i++) {
        if (to_transpose)
            addend = A[size_A.cols*row + i] & B[size_A.cols*col + i];
        else
            // jump through elements in chosen column
            addend = A[size_A.cols * row + i] & B[size_B.cols * i + col];
        // count the number of ones by modulo 2
        element ^= addend;
    } 
    return element;
}

byte compute_element_via_J(size_t row, size_t col,
                           const byte *A, matrix_size size_A,
                           const byte *B, matrix_size size_B, const byte *J)
{
    size_t i;
    byte addend, element = 0;
    // we use only the columns that J contains
    assert(size_A.cols*size_A.rows == SIZE_H);
    assert(size_A.cols == PARAM_N); size_t k = 0;
    for (i=0; i<size_A.cols; i++) {
        if (J[i] == 1) {
            /* pick needed row in A and needed column in B*/
            addend = A[size_A.cols*row + i] & B[size_B.cols*col + k];
            //count the number of ones by modulo 2
            element ^= addend;
            assert(element == 0 || element == 1);
            k++;
        }
    }
    
    return element;
}


void random_matrix(byte matrice[], uint32_t size)
{    

    randombytes(matrice, size*sizeof(byte));
    // get the binary values from bytes
    for (uint32_t i=0; i<size; i++) {
        matrice[i] %= 2;
    }
}

void initialize_H_J(byte H_J[], byte J[])
{
    // go for each column
    for (uint32_t i=0; i<PARAM_N; i++) {
        if (J[i] == 1) {
            // put these H column to H_J
        }
        else {
        }

            // H_J не надо хранить. Надо каждый раз просто выбирать J столбцы из H
    }
}

void compute_sha256(const char* str, unsigned char* output) 
{
    EVP_MD_CTX* mdctx;
    const EVP_MD* md = EVP_sha256();
    unsigned int len = 0;

    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, str, strlen(str));
    EVP_DigestFinal_ex(mdctx, output, &len);
    EVP_MD_CTX_free(mdctx);
}

            

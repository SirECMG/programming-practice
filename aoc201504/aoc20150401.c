#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include <openssl/md5.h>


void itos(int i, char num_buf[], int num_buf_len) {
    snprintf(num_buf, num_buf_len, "%d", i);
    return;
}

void convert_to_md5(char *plaintext, unsigned int len, unsigned char digest[MD5_DIGEST_LENGTH]) {
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, plaintext, len);
    MD5_Final(digest, &ctx);
}

/*
int verify_reward(const char *hex_digest) {
    for (int i = 0; i < 5; ++i) {
        if (hex_digest[i] != '0') {
            return 0;
        }
    }

    return 1;
}*/

int verify_reward(const unsigned char digest[MD5_DIGEST_LENGTH]) {
    return digest[0] == 0x00 &&
           digest[1] == 0x00 &&
           (digest[2] & 0xF0) == 0x00;
}

void digest_to_hex(
    const unsigned char digest[MD5_DIGEST_LENGTH],
    char hex_digest[33]
) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&hex_digest[i * 2], "%02x", digest[i]); // i need to understand what it is doing here..
    }

    hex_digest[32] = '\0';
}

int main() {

    char input[1024];
    char buffer[1024];
    if(fscanf(stdin, "%s", input) != 1) {
        printf("something went wrong reading from stdin\n");
        return EXIT_FAILURE;
    }

    int i = 0;
    char num_buf[1024];
    int num_buf_len = sizeof(num_buf) / sizeof(num_buf[0]);

    unsigned char digest[MD5_DIGEST_LENGTH];

    char hex_digest[33];
    do {
        //itos(i, num_buf, num_buf_len);
        snprintf(buffer, sizeof(buffer), "%s%d", input, i); // improvement made... we can just use snprintf to create a buffer to output a string  with formattted input
        //strcat(buffer, num_buf);
        //snprintf(buffer, sizeof(buffer), "%s%s", input, num_buf);
        printf("%s\n", buffer);
        convert_to_md5(buffer, strlen(buffer), digest);
        //digest_to_hex(digest, hex_digest);
        i++;
    } while(verify_reward(digest) != 1);

    printf("%d\n", i - 1);



    return EXIT_SUCCESS;
}


/*
 *
 *
 *  goal: count lowest number that combines with md5 to get 5 zeros
 *
 *
 *  todo: 
 *
 *  - function to get 5 zeroes from string
 *  - get secret from input file // done
 *  - get current i attempt // done
 *  - combine secret with i
 *
 *
 *  "abc"
 *  i is an int
 *
 *  it look slike snprintf combines buffer with integer...
 *
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * */

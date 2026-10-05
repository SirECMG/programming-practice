#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <openssl/md5.h>


void itos(int i, char num_buf[], int num_buf_len) {
    snprintf(num_buf, num_buf_len, "%d", i);
}


void convert_to_md5(
    char *plaintext,
    unsigned int len,
    unsigned char digest[MD5_DIGEST_LENGTH]
) {
    MD5_CTX ctx;

    MD5_Init(&ctx);
    MD5_Update(&ctx, plaintext, len);
    MD5_Final(digest, &ctx);
}


int verify_reward(const char *hex_digest) {
    for (int i = 0; i < 5; ++i) {
        if (hex_digest[i] != '0') {
            return 0;
        }
    }

    return 1;
}


void digest_to_hex(
    const unsigned char digest[MD5_DIGEST_LENGTH],
    char hex_digest[33]
) {
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        sprintf(&hex_digest[i * 2], "%02x", digest[i]);
    }

    hex_digest[32] = '\0';
}


int main(void) {
    char input[1024];
    char buffer[1024];

    if (fscanf(stdin, "%1023s", input) != 1) {
        printf("something went wrong reading from stdin\n");
        return EXIT_FAILURE;
    }

    int i = 0;

    char num_buf[1024];
    int num_buf_len = sizeof(num_buf) / sizeof(num_buf[0]);

    unsigned char digest[MD5_DIGEST_LENGTH];
    char hex_digest[33];

    do {
        itos(i, num_buf, num_buf_len);

        // Build a fresh string every iteration:
        // abc0
        // abc1
        // abc2
        snprintf(
            buffer,
            sizeof(buffer),
            "%s%s",
            input,
            num_buf
        );

        printf("%s\n", buffer);

        // Hash only the actual string, not all 1024 bytes.
        convert_to_md5(
            buffer,
            strlen(buffer),
            digest
        );

        // Convert raw 16-byte MD5 into 32-character hex string.
        digest_to_hex(
            digest,
            hex_digest
        );

        i++;

    } while (verify_reward(hex_digest) != 1);

    printf("number: %d\n", i - 1);
    printf("candidate: %s\n", buffer);
    printf("md5: %s\n", hex_digest);

    return EXIT_SUCCESS;
}

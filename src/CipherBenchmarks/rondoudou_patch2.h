#ifndef PATCH2_RONDOUDOU_PATCH2_H
#define PATCH2_RONDOUDOU_PATCH2_H

#include <stdint.h>

extern int rondoudou_patch_call_level;
extern uintptr_t rondoudou_patch_key;
extern uintptr_t rondoudou_patch_offset;
extern uintptr_t *rondoudou_patch_return_addr_addr;

int print_log(const char *format, ...);

#ifdef NOCIPHER

#define cipher
#define decipher
#define change_one_address(i, new_key)
#define change_key(new_key)

#else

#define cipher \
    do {           \
        rondoudou_patch_return_addr_addr = (uintptr_t *)__builtin_frame_address(0) + rondoudou_patch_offset; \
        print_log("cipher  :      base return address = %018p\n", __builtin_return_address(0));\
        /*print_log("cipher  : Return address = %018p\n", *rondoudou_patch_return_addr_addr);*/\
        *rondoudou_patch_return_addr_addr = *rondoudou_patch_return_addr_addr ^ rondoudou_patch_key; \
        print_log("cipher  : encrypted return address = %018p\n", __builtin_return_address(0));\
        /*print_log("cipher  : Return address = %018p\n", *rondoudou_patch_return_addr_addr);*/\
        rondoudou_patch_call_level++;                                                                        \
    } while(0)

#define decipher \
    do {             \
        rondoudou_patch_return_addr_addr = (uintptr_t *)__builtin_frame_address(0) + rondoudou_patch_offset; \
        print_log("decipher: encrypted return address = %018p\n", __builtin_return_address(0));\
        /*print_log("decipher: Return address = %018p\n", *rondoudou_patch_return_addr_addr);*/\
        *rondoudou_patch_return_addr_addr = *rondoudou_patch_return_addr_addr ^ rondoudou_patch_key; \
        print_log("decipher: decrypted return address = %018p\n", __builtin_return_address(0));\
        /*print_log("decipher: Return address = %018p\n", *rondoudou_patch_return_addr_addr);*/\
        rondoudou_patch_call_level--;                                                                        \
    } while(0)

#define change_one_address(i, new_key) \
        if (rondoudou_patch_call_level > (i)) {                                                                    \
            rondoudou_patch_return_addr_addr = (uintptr_t *)__builtin_frame_address(i) + rondoudou_patch_offset; \
            print_log("%d:   encrypted ret address = %018p\n", i, *rondoudou_patch_return_addr_addr);                \
            *rondoudou_patch_return_addr_addr = *rondoudou_patch_return_addr_addr ^ rondoudou_patch_key;         \
            print_log("%d:   decrypted ret address = %018p\n", i, *rondoudou_patch_return_addr_addr);                \
            *rondoudou_patch_return_addr_addr = *rondoudou_patch_return_addr_addr ^ (new_key);                     \
            print_log("%d: reencrypted ret address = %018p\n", i, *rondoudou_patch_return_addr_addr);                \
        }                                                                                                        \

#define change_key(new_key) \
    do {                        \
        print_log("\n--- Changing key ---\n");                                                                   \
        print_log("Call_level = %d\n", rondoudou_patch_call_level);                                              \
                            \
        change_one_address(0, new_key);                    \
        change_one_address(1, new_key);                    \
        change_one_address(2, new_key);                    \
        change_one_address(3, new_key);                    \
        change_one_address(4, new_key);                    \
        change_one_address(5, new_key);                    \
        change_one_address(6, new_key);                    \
        change_one_address(7, new_key);                    \
        change_one_address(8, new_key);                    \
        change_one_address(9, new_key);                    \
        change_one_address(10, new_key);                    \
        change_one_address(11, new_key);                    \
        change_one_address(12, new_key)                    \
        change_one_address(13, new_key);                    \
        change_one_address(14, new_key);                    \
        change_one_address(15, new_key);                    \
        change_one_address(16, new_key);                    \
        change_one_address(17, new_key);                    \
        change_one_address(18, new_key);                    \
        change_one_address(19, new_key);                    \
        change_one_address(20, new_key);                    \
        change_one_address(21, new_key);                    \
        change_one_address(22, new_key);                    \
        change_one_address(23, new_key);                    \
        change_one_address(24, new_key);                    \
        change_one_address(25, new_key);                    \
        change_one_address(26, new_key);                    \
                            \
        print_log("\n");                        \
        rondoudou_patch_key = new_key;                                                                                \
    } while (0)

#endif // NOCIPHER
#endif //PATCH2_RONDOUDOU_PATCH2_H

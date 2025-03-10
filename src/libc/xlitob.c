#include "common.h"
#include "xstdio.h"

#define BUFF_LEN 0x18

static u8 ldigs[] = "0123456789abcdef";
static u8 udigs[] = "0123456789ABCDEF";

void _Litob(_Pft *args, u8 type) {
    u8 buff[BUFF_LEN];
    const u8 *digs;
    s32 base;
    s32 i;
    unsigned long long ullval;

    if (type == 'X') {
        digs = udigs;
    } else {
        digs = ldigs;
    }

    base = (type == 'o') ? 8 : ((type != 'x' && type != 'X') ? 10 : 16);
    i = BUFF_LEN;
    ullval = args->v.ll;

    if ((type == 'd' || type == 'i') && args->v.ll < 0) {
        ullval = -ullval;
    }

    if (ullval != 0 || args->prec != 0) {
        buff[--i] = digs[ullval % base];
    }

    args->v.ll = ullval / base;

    while (args->v.ll > 0 && i > 0) {
        lldiv_t qr = lldiv(args->v.ll, base);
        
        args->v.ll = qr.quot;
        buff[--i] = digs[qr.rem];
    }

    args->n1 = BUFF_LEN - i;

    memcpy(args->s, buff + i, args->n1);

    if (args->n1 < args->prec) {
        args->nz0 = args->prec - args->n1;
    }

    if (args->prec < 0 && (args->flags & (FLAGS_ZERO | FLAGS_MINUS)) == FLAGS_ZERO) {
        i = args->width - args->n0 - args->nz0 - args->n1;
        
        if (i > 0) {
            args->nz0 += i;
        }
    }
}

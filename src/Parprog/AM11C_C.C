/* AM11C.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
        -lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int am11c_c(complex *a, complex *b, complex *s, integer *n)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3, i__4, i__5;
    complex q__1, q__2;

    /* Local variables */
    static integer i__, j, k;
    static complex r__;


#define a_subscr(a_1,a_2) (a_2)*a_dim1 + a_1
#define a_ref(a_1,a_2) a[a_subscr(a_1,a_2)]
#define b_subscr(a_1,a_2) (a_2)*b_dim1 + a_1
#define b_ref(a_1,a_2) b[b_subscr(a_1,a_2)]

    /* Parameter adjustments */
    --s;
    b_dim1 = *n;
    b_offset = b_dim1 + 1;
    b -= b_offset;
    a_dim1 = *n;
    a_offset = a_dim1 + 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
        i__2 = *n;
        for (i__ = 1; i__ <= i__2; ++i__) {
            r__.r = 0.f, r__.i = 0.f;
            i__3 = *n;
            for (j = 1; j <= i__3; ++j) {
/* L1: */
                i__4 = b_subscr(j, k);
                i__5 = a_subscr(i__, j);
                q__2.r = b[i__4].r * a[i__5].r - b[i__4].i * a[i__5].i, 
                        q__2.i = b[i__4].r * a[i__5].i + b[i__4].i * a[i__5]
                        .r;
                q__1.r = r__.r + q__2.r, q__1.i = r__.i + q__2.i;
                r__.r = q__1.r, r__.i = q__1.i;
            }
/* L2: */
            i__4 = i__;
            s[i__4].r = r__.r, s[i__4].i = r__.i;
        }
        i__4 = *n;
        for (j = 1; j <= i__4; ++j) {
/* L3: */
            i__2 = b_subscr(j, k);
            i__5 = j;
            b[i__2].r = s[i__5].r, b[i__2].i = s[i__5].i;
        }
    }
    return 0;
} /* am11c_c */

#undef b_ref
#undef b_subscr
#undef a_ref
#undef a_subscr

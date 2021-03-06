/* afg5c.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
        -lf2c -lm   (in that order)
*/

#include "f2c.h"
#include "some_maths.h"
/* Table of constant values */

static complex c_b16 = {-1.f,0.f};

/* Subroutine */ int afg5c_c(complex *a, integer *m, integer *n, integer *
        nlead, integer *ierr)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    real r__1, r__2;
    complex q__1, q__2;

    /* Builtin functions */
    double r_imag(complex *), c_abs(complex *);
    void c_div(complex *, complex *, complex *);

    /* Local variables */
    static integer i__, j, k, l;
    static real r__;
    static complex t;
    static real x;
    static integer jj;
    extern /* Subroutine */ int utafsi_c(char *, char *, char *, char *, char *
            , integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static integer kp1, nm1;


#define a_subscr(a_1,a_2) (a_2)*a_dim1 + a_1
#define a_ref(a_1,a_2) a[a_subscr(a_1,a_2)]

/* ********************************************************************C 
*/
/*  LU-PA��O�EH�E MATP��� A METO�OM �AYCCA C B��OPOM                  C */
/*  BE�Y�E�O ��EMEHTA �O CTO���Y                                      C */
/*                                                                    C */
/*  M-��C�O CTPOK MATP���(T��:INTEGER)                                C */
/*  N-PA�MEP MATP���(T��:INTEGER)                                     C */
/*  A-MATP��A M*N,HA BXO�E CO�EP��T �CXO�HY� MATP��Y,                 C */
/*  HA B�XO�E HA COOTBETCTBY���X MECTAX HAXO��TC� ��EMEHT�            C */
/*  MATP��� U � �O���A�OHA��H�E ��EMEHT�                              C */
/*  MAPT��� INVERSE(L)(T��:COMPLEX)                                   C */
/*  NLEAD-BEKTOP ���H� N,HA B�XO�E CO�EP��T BEKTOP,�OPO��A����        C */
/*  MATP��Y �EPECTAHOBOK(T��:INTEGER)                                 C */
/*  IERR-�EPEMEHHA�,YKA��BA��A� �P���HY B�XO�A(T��:INTEGER)           C */
/*                                                                    C */
/* ********************************************************************C 
*/

/*  YCTAHOB�EH�E KOHTPO�� HA BO�MO�HOCT� �EPE�O�HEH */
    /* Parameter adjustments */
    a_dim1 = *m;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    --nlead;

    /* Function Body */
    x = 0.f;
/* L10: */

/*  �POBEPKA �PAB���HOCT� �A�AH�� �APAMETPOB M � N */
    if (*n >= 1 && *m >= 1) {
        goto L20;
    }
    *ierr = 65;
    utafsi_c("A", "F", "G", "5", "C", ierr, 1L, 1L, 1L, 1L, 1L);
    goto L200;
L20:
    *ierr = 0;
    nm1 = *n - 1;
    if (nm1 < 1) {
        goto L190;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
        kp1 = k + 1;

/*  HAXO��EH�E �H�EKCA BE�Y�E�O ��EMEHTA L */
        l = k;
        i__2 = a_subscr(k, k);
        r__ = (r__1 = a[i__2].r, abs(r__1)) + (r__2 = (real)r_imag(&a_ref(k, 
                k)), abs(r__2));
        i__2 = *n;
        for (j = kp1; j <= i__2; ++j) {
            i__3 = a_subscr(j, k);
            if ((r__1 = a[i__3].r, abs(r__1)) + (r__2 = (real)r_imag(&a_ref(j,
                     k)), abs(r__2)) <= r__) {
                goto L30;
            }
            l = j;
            i__3 = a_subscr(j, k);
            r__ = (r__1 = a[i__3].r, abs(r__1)) + (r__2 = (real)r_imag(&a_ref(
                    j, k)), abs(r__2));
L30:
/* L40: */
            ;
        }
        nlead[k] = l;
        if ((real)c_abs(&a_ref(l, k)) == 0.f) {
            goto L160;
        }

/*  �EPECTAHOBKA,EC�� TPE�YETC */
        if (l == k) {
            goto L50;
        }
        i__2 = a_subscr(l, k);
        t.r = a[i__2].r, t.i = a[i__2].i;
        i__2 = a_subscr(l, k);
        i__3 = a_subscr(k, k);
        a[i__2].r = a[i__3].r, a[i__2].i = a[i__3].i;
        i__2 = a_subscr(k, k);
        a[i__2].r = t.r, a[i__2].i = t.i;
L50:

/*  B���C�EH�E MHO��TE�E */
        c_div(&q__1, &c_b16, &a_ref(k, k));
        t.r = q__1.r, t.i = q__1.i;
        j = *n - k;
        i__ = j % 5 + k;
        if (i__ == k) {
            goto L70;
        }
        i__2 = i__;
        for (j = kp1; j <= i__2; ++j) {
            i__3 = a_subscr(j, k);
            i__4 = a_subscr(j, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
/* L60: */
        }
L70:
        ++i__;
        if (i__ > *n) {
            goto L90;
        }
        i__2 = *n;
        for (j = i__; j <= i__2; j += 5) {
            i__3 = a_subscr(j, k);
            i__4 = a_subscr(j, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(j + 1, k);
            i__4 = a_subscr(j + 1, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(j + 2, k);
            i__4 = a_subscr(j + 2, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(j + 3, k);
            i__4 = a_subscr(j + 3, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(j + 4, k);
            i__4 = a_subscr(j + 4, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
/* L80: */
        }
L90:

/*  �AYCCOBO �CK���EH�E */
        i__2 = *n;
        for (j = kp1; j <= i__2; ++j) {
            i__3 = a_subscr(l, j);
            t.r = a[i__3].r, t.i = a[i__3].i;
            if (l == k) {
                goto L100;
            }
            i__3 = a_subscr(l, j);
            i__4 = a_subscr(k, j);
            a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
            i__3 = a_subscr(k, j);
            a[i__3].r = t.r, a[i__3].i = t.i;
L100:
            jj = *n - k;
            i__ = jj % 4 + k;
            if (i__ == k) {
                goto L120;
            }
            i__3 = i__;
            for (jj = kp1; jj <= i__3; ++jj) {
                i__4 = a_subscr(jj, j);
                i__5 = a_subscr(jj, j);
                i__6 = a_subscr(jj, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L110: */
            }
L120:
            ++i__;
            if (i__ > *n) {
                goto L140;
            }
            i__3 = *n;
            for (jj = i__; jj <= i__3; jj += 4) {
                i__4 = a_subscr(jj, j);
                i__5 = a_subscr(jj, j);
                i__6 = a_subscr(jj, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 1, j);
                i__5 = a_subscr(jj + 1, j);
                i__6 = a_subscr(jj + 1, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 2, j);
                i__5 = a_subscr(jj + 2, j);
                i__6 = a_subscr(jj + 2, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 3, j);
                i__5 = a_subscr(jj + 3, j);
                i__6 = a_subscr(jj + 3, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L130: */
            }
L140:
/* L150: */
            ;
        }
        goto L170;
L160:
        *ierr = -k;
L170:
/* L180: */
        ;
    }
L190:
    nlead[*n] = *n;
    if ((real)c_abs(&a_ref(*n, *n)) == 0.f) {
        *ierr = -(*n);
    }
    if (*ierr == 0) {
        goto L200;
    }
    utafsi_c("A", "F", "G", "5", "C", ierr, 1L, 1L, 1L, 1L, 1L);
L200:
    return 0;
} /* afg5c_c */

#undef a_ref
#undef a_subscr

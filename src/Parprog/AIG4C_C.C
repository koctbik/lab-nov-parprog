/* aig4c.f -- translated by f2c (version 19970805).
   You must link the resulting object file with the libraries:
        -lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static complex c_b17 = {1.f,0.f};

/* Subroutine */ int aig4c_c(complex *a, integer *m, integer *n,
        integer *nlead, complex *z__, integer *ierr)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    complex q__1, q__2;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *);

    /* Local variables */
    extern /* Subroutine */ int afg5c_c(complex *, integer *, integer *,
            integer *, integer *);
    static integer i__, j, k, l;
    static complex t;
    static real x;
    static integer kb, jj;
    extern /* Subroutine */ int utafsi_c(char *, char *, char *, char *,
            char *, integer *, ftnlen, ftnlen, ftnlen, ftnlen, ftnlen);
    static integer kp1, nm1;


#define a_subscr(a_1,a_2) (a_2)*a_dim1 + a_1
#define a_ref(a_1,a_2) a[a_subscr(a_1,a_2)]

/* ***************************************** */
/*   OPA™EHˆE MATPˆ–› A METO„OM ƒAYCCA      */
/*  C B›OPOM BE„Y™EƒO ‹EMEHTA O CTO‹–Y.  */
/* ***************************************** */

/*  YCTAHOB‹EHˆE KOHTPO‹Ÿ HA BO‡MO†HOCTœ EPEO‹HEH */
    /* Parameter adjustments */
    a_dim1 = *m;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    --nlead;
    --z__;

    /* Function Body */
    x = 0.f;
/* L10: */

/*  POBEPKA PABˆ‹œHOCTˆ ‡A„AHˆŸ APAMETPOB M ˆ N */
    if (*n >= 1 && *m >= 1) {
        goto L20;
    }
    *ierr = 65;
    utafsi_c("A", "I", "G", "4", "C", ierr, 1L, 1L, 1L, 1L, 1L);
    goto L270;
L20:
    *ierr = 0;
    afg5c_c(&a[a_offset], m, n, &nlead[1], ierr);
    if (*ierr == 0) {
        goto L30;
    }
    utafsi_c("A", "I", "G", "4", "C", ierr, 1L, 1L, 1L, 1L, 1L);
    goto L270;
L30:

/*  B›—ˆC‹EHˆE MATPˆ–› INVERSE(U) */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
        i__2 = a_subscr(k, k);
        c_div(&q__1, &c_b17, &a_ref(k, k));
        a[i__2].r = q__1.r, a[i__2].i = q__1.i;
        i__2 = a_subscr(k, k);
        q__1.r = -a[i__2].r, q__1.i = -a[i__2].i;
        t.r = q__1.r, t.i = q__1.i;
        j = k - 1;
        i__ = j % 5;
        if (i__ == 0) {
            goto L50;
        }
        i__2 = i__;
        for (jj = 1; jj <= i__2; ++jj) {
            i__3 = a_subscr(jj, k);
            i__4 = a_subscr(jj, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
/* L40: */
        }
L50:
        ++i__;
        if (i__ > j) {
            goto L70;
        }
        i__2 = j;
        for (jj = i__; jj <= i__2; jj += 5) {
            i__3 = a_subscr(jj, k);
            i__4 = a_subscr(jj, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(jj + 1, k);
            i__4 = a_subscr(jj + 1, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(jj + 2, k);
            i__4 = a_subscr(jj + 2, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(jj + 3, k);
            i__4 = a_subscr(jj + 3, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
            i__3 = a_subscr(jj + 4, k);
            i__4 = a_subscr(jj + 4, k);
            q__1.r = t.r * a[i__4].r - t.i * a[i__4].i, q__1.i = t.r * a[i__4]
                    .i + t.i * a[i__4].r;
            a[i__3].r = q__1.r, a[i__3].i = q__1.i;
/* L60: */
        }
L70:
        kp1 = k + 1;
        if (*n < kp1) {
            goto L130;
        }
        i__2 = *n;
        for (j = kp1; j <= i__2; ++j) {
            i__3 = a_subscr(k, j);
            t.r = a[i__3].r, t.i = a[i__3].i;
            i__3 = a_subscr(k, j);
            a[i__3].r = 0.f, a[i__3].i = 0.f;
            i__ = k % 4;
            if (i__ == 0) {
                goto L90;
            }
            i__3 = i__;
            for (jj = 1; jj <= i__3; ++jj) {
                i__4 = a_subscr(jj, j);
                i__5 = a_subscr(jj, j);
                i__6 = a_subscr(jj, k);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L80: */
            }
L90:
            ++i__;
            if (i__ > k) {
                goto L110;
            }
            i__3 = k;
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
/* L100: */
            }
L110:
/* L120: */
            ;
        }
L130:
/* L140: */
        ;
    }

/*  B›—ˆC‹EHˆE MATPˆ–› INVERSE(U)*INVERSE(L) */
    nm1 = *n - 1;
    if (nm1 < 1) {
        goto L270;
    }
    i__1 = nm1;
    for (kb = 1; kb <= i__1; ++kb) {
        k = *n - kb;
        kp1 = k + 1;
        i__2 = *n;
        for (i__ = kp1; i__ <= i__2; ++i__) {
            i__3 = i__;
            i__4 = a_subscr(i__, k);
            z__[i__3].r = a[i__4].r, z__[i__3].i = a[i__4].i;
            i__3 = a_subscr(i__, k);
            a[i__3].r = 0.f, a[i__3].i = 0.f;
/* L150: */
        }
        i__2 = *n;
        for (j = kp1; j <= i__2; ++j) {
            i__3 = j;
            t.r = z__[i__3].r, t.i = z__[i__3].i;
            i__ = *n % 4;
            if (i__ == 0) {
                goto L170;
            }
            i__3 = i__;
            for (jj = 1; jj <= i__3; ++jj) {
                i__4 = a_subscr(jj, k);
                i__5 = a_subscr(jj, k);
                i__6 = a_subscr(jj, j);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L160: */
            }
L170:
            ++i__;
            if (i__ > *n) {
                goto L190;
            }
            i__3 = *n;
            for (jj = i__; jj <= i__3; jj += 4) {
                i__4 = a_subscr(jj, k);
                i__5 = a_subscr(jj, k);
                i__6 = a_subscr(jj, j);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 1, k);
                i__5 = a_subscr(jj + 1, k);
                i__6 = a_subscr(jj + 1, j);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 2, k);
                i__5 = a_subscr(jj + 2, k);
                i__6 = a_subscr(jj + 2, j);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
                i__4 = a_subscr(jj + 3, k);
                i__5 = a_subscr(jj + 3, k);
                i__6 = a_subscr(jj + 3, j);
                q__2.r = t.r * a[i__6].r - t.i * a[i__6].i, q__2.i = t.r * a[
                        i__6].i + t.i * a[i__6].r;
                q__1.r = a[i__5].r + q__2.r, q__1.i = a[i__5].i + q__2.i;
                a[i__4].r = q__1.r, a[i__4].i = q__1.i;
/* L180: */
            }
L190:
/* L200: */
            ;
        }
        l = nlead[k];
        if (l == k) {
            goto L250;
        }
        i__ = *n % 3;
        if (i__ == 0) {
            goto L220;
        }
        i__2 = i__;
        for (jj = 1; jj <= i__2; ++jj) {
            i__3 = a_subscr(jj, l);
            t.r = a[i__3].r, t.i = a[i__3].i;
            i__3 = a_subscr(jj, l);
            i__4 = a_subscr(jj, k);
            a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
            i__3 = a_subscr(jj, k);
            a[i__3].r = t.r, a[i__3].i = t.i;
/* L210: */
        }
L220:
        ++i__;
        if (i__ > *n) {
            goto L240;
        }
        i__2 = *n;
        for (jj = i__; jj <= i__2; jj += 3) {
            i__3 = a_subscr(jj, l);
            t.r = a[i__3].r, t.i = a[i__3].i;
            i__3 = a_subscr(jj, l);
            i__4 = a_subscr(jj, k);
            a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
            i__3 = a_subscr(jj, k);
            a[i__3].r = t.r, a[i__3].i = t.i;
            i__3 = a_subscr(jj + 1, l);
            t.r = a[i__3].r, t.i = a[i__3].i;
            i__3 = a_subscr(jj + 1, l);
            i__4 = a_subscr(jj + 1, k);
            a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
            i__3 = a_subscr(jj + 1, k);
            a[i__3].r = t.r, a[i__3].i = t.i;
            i__3 = a_subscr(jj + 2, l);
            t.r = a[i__3].r, t.i = a[i__3].i;
            i__3 = a_subscr(jj + 2, l);
            i__4 = a_subscr(jj + 2, k);
            a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
            i__3 = a_subscr(jj + 2, k);
            a[i__3].r = t.r, a[i__3].i = t.i;
/* L230: */
        }
L240:
L250:
/* L260: */
        ;
    }
L270:
    return 0;
} /* aig4c_c */

#undef a_ref
#undef a_subscr

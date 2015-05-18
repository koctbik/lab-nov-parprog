/* AM11D.f -- translated by f2c (version 19970805).
You must link the resulting object file with the libraries:
-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int am11d_c(doublereal *a, doublereal *b, doublereal *s,
	integer *n)
{
	/* System generated locals */
	integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3;

	/* Local variables */
	static integer i__, j, k;
	static doublereal r__;


#define a_ref(a_1,a_2) a[(a_2)*a_dim1 + a_1]
#define b_ref(a_1,a_2) b[(a_2)*b_dim1 + a_1]

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
			r__ = 0.;
			i__3 = *n;
			for (j = 1; j <= i__3; ++j) {
				/* L1: */
				r__ += b_ref(j, k) * a_ref(i__, j);
			}
			/* L2: */
			s[i__] = r__;
		}
		i__2 = *n;
		for (j = 1; j <= i__2; ++j) {
			/* L3: */
			b_ref(j, k) = s[j];
		}
	}
	return 0;
} /* am11d_c */

#undef b_ref
#undef a_ref

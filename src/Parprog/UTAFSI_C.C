int utafsi_c(int *n1, int *n2, int *n3, int *n4, int *n5, int *ierr)
{
    if (*ierr == 0) { goto L9;}
    if (*ierr <= -1) { goto L1;}
    if (*ierr == 65) { goto L3;}
    if (*ierr == 66) { goto L5;}
    if (*ierr == 67) { goto L7;}
L1:
    printf("\n ˆ‹ˆOTEKA HˆB– MƒY, O„POƒPAMMA %c%c%c%c%c"
           ": HE”ATA‹œHAŸ O˜ˆKA \n   N 1 - MATPˆ–A B›PO†„EHA.\n",
            *n1, *n2, *n3, *n4, *n5);
    goto L9;
L3:
    printf("\n ˆ‹ˆOTEKA HˆB– MƒY, O„POƒPAMMA %c%c%c%c%c"
      ": ”ATA‹œHAŸ O˜ˆKA \n   N 1 - ‡HA—EHˆE N ˆ‹ˆ M MEHœ˜E ˆ‹ˆ PABHO 0.\n",
            *n1, *n2, *n3, *n4, *n5);
    goto L9;
L5:
    printf("\n ˆ‹ˆOTEKA HˆB– MƒY, O„POƒPAMMA %c%c%c%c%c"
      ": ”ATA‹œHAŸ O˜ˆKA \n   N 2 - POˆ‡O˜‹O EPEO‹HEHˆE"
      " –EHTPA‹œHOƒO PO–ECCOPA.\n",*n1, *n2, *n3, *n4, *n5);
    goto L9;
L7:
    printf("\n ˆ‹ˆOTEKA HˆB– MƒY, O„POƒPAMMA %c%c%c%c%c"
           ": HE”ATA‹œHAŸ O˜ˆKA \n   N 2 - CˆCTEMA HECOBMECTHA.\n",
            *n1, *n2, *n3, *n4, *n5);
L9:
    return 0;
} /* utafsi_c */

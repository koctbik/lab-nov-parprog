int utafsi_c(int *n1, int *n2, int *n3, int *n4, int *n5, int *ierr)
{
    if (*ierr == 0) { goto L9;}
    if (*ierr <= -1) { goto L1;}
    if (*ierr == 65) { goto L3;}
    if (*ierr == 66) { goto L5;}
    if (*ierr == 67) { goto L7;}
L1:
    printf("\n �����OTEKA H�B� M�Y, �O��PO�PAMMA %c%c%c%c%c"
           ": HE�ATA��HA� O���KA \n   N 1 - MATP��A B�PO��EHA.\n",
            *n1, *n2, *n3, *n4, *n5);
    goto L9;
L3:
    printf("\n �����OTEKA H�B� M�Y, �O��PO�PAMMA %c%c%c%c%c"
      ": �ATA��HA� O���KA \n   N 1 - �HA�EH�E N ��� M MEH��E ��� PABHO 0.\n",
            *n1, *n2, *n3, *n4, *n5);
    goto L9;
L5:
    printf("\n �����OTEKA H�B� M�Y, �O��PO�PAMMA %c%c%c%c%c"
      ": �ATA��HA� O���KA \n   N 2 - �PO��O��O �EPE�O�HEH�E"
      " �EHTPA��HO�O �PO�ECCOPA.\n",*n1, *n2, *n3, *n4, *n5);
    goto L9;
L7:
    printf("\n �����OTEKA H�B� M�Y, �O��PO�PAMMA %c%c%c%c%c"
           ": HE�ATA��HA� O���KA \n   N 2 - C�CTEMA HECOBMECTHA.\n",
            *n1, *n2, *n3, *n4, *n5);
L9:
    return 0;
} /* utafsi_c */

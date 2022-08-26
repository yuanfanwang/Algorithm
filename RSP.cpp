
char win(char a, char b) {
    if (a==b) return a;
    if (a!='P'&&b!='P') return 'R';
    if (a!='R'&&b!='R') return 'S';
    return 'P';
}

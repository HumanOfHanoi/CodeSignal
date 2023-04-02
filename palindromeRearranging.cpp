bool solution(string inputString) {
    int freq[260] = {0}, odd = 0;
    for(int i=0; i<inputString.size(); i++)
        freq[(int)inputString[i]]++;
    for(int i=0; i<260; i++) if(freq[i] % 2)
        odd++;
    return (odd <= 1);
}

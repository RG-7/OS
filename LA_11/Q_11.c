#include<stdio.h> // Header File
#define MAX 10 // Maximum number of Frames Possible

void fifo(int no_of_frames, int ref_str[], int n) {
    int i, j, k, flag=0, count=0, frames[MAX], fcount=0;
    printf("\nFIFO Page Replacement Algorithm:\n");
    for(i=0; i<no_of_frames; i++)
        frames[i] = -1;
	
    for(i=0; i<n; i++) {
        flag=0;
        for(j=0; j<no_of_frames; j++) {
            if(frames[j] == ref_str[i]) {
                printf("\t");
                flag=1;
                break;
            }
        }
        if(flag == 0) {
            printf("F");
            frames[fcount] = ref_str[i];
            fcount = (fcount+1)%no_of_frames;
            count++;
        }
        for(k=0; k<no_of_frames; k++)
            if(frames[k] != -1)
                printf(" %d", frames[k]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", count);
}

// LRU Page Replacement Algorithm
void lru(int no_of_frames, int ref_str[], int n) {
    int i, j, k, flag=0, count=0, frames[MAX], fcount=0, least[MAX];
    printf("\nLRU Page Replacement Algorithm:\n");
    for(i=0; i<no_of_frames; i++) {
        frames[i] = -1;
        least[i] = -1;
    }
	
    for(i=0; i<n; i++) {
        flag=0;
        for(j=0; j<no_of_frames; j++) {
            if(frames[j] == ref_str[i]) {
                printf("\t");
                flag=1;
                least[j] = i;
                break;
            }
        }
        if(flag == 0) {
            printf("F");
            if(i < no_of_frames) {
                frames[i] = ref_str[i];
                least[i] = i;
            } else {
                int min = 999, repindex;
                for(k=0; k<no_of_frames; k++) {
                    if(least[k] < min) {
                        min = least[k];
                        repindex = k;
                    }
                }
                frames[repindex] = ref_str[i];
                least[repindex] = i;
            }
            count++;
        }
        for(k=0; k<no_of_frames; k++)
            if(frames[k] != -1)
                printf(" %d", frames[k]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", count);
}

// Optimal Page Replacement Algorithm
void optimal(int no_of_frames, int ref_str[], int n) {
    int i, j, k, flag=0, count=0, frames[MAX], fcount=0, next[MAX];
    printf("\nOptimal Page Replacement Algorithm:\n");
    for(i=0; i<no_of_frames; i++)
        frames[i] = -1;
	
    for(i=0; i<n; i++) {
        flag=0;
        for(j=0; j<no_of_frames; j++) {
            if(frames[j] == ref_str[i]) {
                printf("\t");
                flag=1;
                break;
            }
        }
        if(flag == 0) {
            printf("F");
            if(i < no_of_frames) {
                frames[i] = ref_str[i];
            } else {
                for(j=0; j<no_of_frames; j++) {
                    int found = 0;
                    for(k=i+1; k<n; k++) {
                        if(frames[j] == ref_str[k]) {
                            next[j] = k;
                            found = 1;
                            break;
                        }
                    }
                    if(!found)
                        next[j] = 999;
                }
                int max = -999, repindex;
                for(j=0; j<no_of_frames; j++) {
                    if(next[j] > max) {
                        max = next[j];
                        repindex = j;
                    }
                }
                frames[repindex] = ref_str[i];
            }
            count++;
        }
        for(k=0; k<no_of_frames; k++)
            if(frames[k] != -1)
                printf(" %d", frames[k]);
        printf("\n");
    }
    printf("\nTotal Page Faults: %d\n", count);
}

int main() {
    int no_of_frames = 3;
    int ref_str[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(ref_str)/sizeof(ref_str[0]);

    fifo(no_of_frames, ref_str, n);
	lru(no_of_frames, ref_str, n);
    optimal(no_of_frames, ref_str, n);

    return 0;
}
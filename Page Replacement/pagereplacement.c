#include<stdio.h>

void optimal(){
    int frames[29], interval[29];
    int pages=29, total_frames, page_faults = 0;
    int m, n, temp, flag, found;
    int position, maximum_interval, previous_frame = -1;
    int reference_string[29] = {7, 0, 1, 2, 3, 0, 4, 2, 2, 3, 5, 7, 1, 4, 2, 3, 2, 0, 1, 4, 7, 5, 2, 3, 2, 7, 0, 1, 5};
    
    printf("\nEnter Total Number of Frames:\t");
    scanf("%d", &total_frames);
    for(m = 0; m < total_frames; m++){
        frames[m] = -1;
    }
    for(m = 0; m < pages; m++){
        flag = 0;
        for(n = 0; n < total_frames; n++){
            if(frames[n] == reference_string[m]){
                flag = 1;
                printf("\t");
                break;
            }
        }
        if(flag == 0){
            if (previous_frame == total_frames - 1) {
                for(n = 0; n < total_frames; n++){
                    for(temp = m + 1; temp < pages; temp++){
                        interval[n] = 0;
                        if (frames[n] == reference_string[temp]){
                            interval[n] = temp - m;
                            break;
                        }
                    }
                }
                found = 0;
                for(n = 0; n < total_frames; n++){
                    if(interval[n] == 0){
                        position = n;
                        found = 1;
                        break;
                    }
                }
            }
            else{
                position = ++previous_frame;
                found = 1;
            }
            if(found == 0){
                maximum_interval = interval[0];
                position = 0;
                for(n = 1; n < total_frames; n++){
                    if(maximum_interval < interval[n]){
                        maximum_interval = interval[n];
                        position = n;
                    }
                }
            }
            frames[position] = reference_string[m];
            printf("FAULT\t");
            page_faults++;
        }
        for(n = 0; n < total_frames; n++){
            if(frames[n] != -1) {
                printf("%d\t", frames[n]);
            }
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults(optimal):\t%d\n", page_faults);
}
void fifo() {
    int page_faults = 0, m, n, s, pages=29, frames;
    int reference_string[29] = {7, 0, 1, 2, 3, 0, 4, 2, 2, 3, 5, 7, 1, 4, 2, 3, 2, 0, 1, 4, 7, 5, 2, 3, 2, 7, 0, 1, 5};
    printf("\nEnter Total Number of Frames:\t");
    {
        scanf("%d", &frames);
    }
    int temp[frames];
    for(m = 0; m < frames; m++){
        temp[m] = -1;
    }
    for(m = 0; m < pages; m++){
        s = 0;
        for(n = 0; n < frames; n++){
            if(reference_string[m] == temp[n])
            {
                s++;
                page_faults--;
            }
        }
        page_faults++;
        if((page_faults <= frames) && (s == 0)){
            temp[m] = reference_string[m];
        }
        else if(s == 0){
            temp[(page_faults - 1) % frames] = reference_string[m];
        }
        printf("\n");
        for(n = 0; n < frames; n++){
            printf("%d\t", temp[n]);
        }
    }
    printf("\nTotal Page Faults(fifo):\t%d\n", page_faults);
}
void lru() {
    int frames[29], temp[29];
    int total_pages=29, m, n, position, k, l, total_frames;
    int a = 0, b = 0, page_fault = 0;
    int pages[29] = {7, 0, 1, 2, 3, 0, 4, 2, 2, 3, 5, 7, 1, 4, 2, 3, 2, 0, 1, 4, 7, 5, 2, 3, 2, 7, 0, 1, 5};
    printf("\nEnter Total Number of Frames:\t");
    scanf("%d", &total_frames);
    for(m = 0; m < total_frames; m++){
        frames[m] = -1;
    }
    
    for(n = 0; n < total_pages; n++){
        a = 0, b = 0;
        for(m = 0; m < total_frames; m++){
            if(frames[m] == pages[n]){
                a = 1;
                b = 1;
                break;
            }
        }
        if(a == 0){
            for(m = 0; m < total_frames; m++){
                if(frames[m] == -1){
                    frames[m] = pages[n];
                    b = 1;
                    break;
                }
            }
        }
        if(b == 0) {
            for(m = 0; m < total_frames; m++){
                temp[m] = 0;
            }
            for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--){
                for(m = 0; m < total_frames; m++){
                    if(frames[m] == pages[k]){
                        temp[m] = 1;
                    }
                }
            }
            for(m = 0; m < total_frames; m++){
                if(temp[m] == 0)
                    position = m;
            }
            frames[position] = pages[n];
            page_fault++;
        }
        printf("\n");
        for(m = 0; m < total_frames; m++){
            printf("%d\t", frames[m]);
        }
    }
    printf("\nTotal Number of Page Faults(LRU):\t%d\n", page_fault);
}
int main() {
    optimal();
    fifo();
    lru();
    return 0;
}
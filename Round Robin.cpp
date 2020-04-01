#include<stdio.h>
#include<string.h>

struct process_Struct {
    char process_name[30];
    int arrival_time, burst_time, completion_time, remaining, waiting_time;
    float avg_waiting;
}temp_Struct;


void faculty(int no_of_process) {

    int count, arrival_Time, burst_Time, quantum_time;
    float avg_waiting=0;
    struct process_Struct faculty_Process[no_of_process];

    for(count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", faculty_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &faculty_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &faculty_Process[count].burst_time);
        puts("");
    }
    printf("Quantum time : ");
    scanf("%d", &quantum_time);

    for(count = 0; count < no_of_process; count++) {
        for(int x = count +1; x < count; x++){
            if(faculty_Process[count].arrival_time > faculty_Process[x].arrival_time) {
                temp_Struct = faculty_Process[count];
                faculty_Process[count] = faculty_Process[x];
                faculty_Process[x] = temp_Struct;
            }
        }
    }


    for(count = 0; count < no_of_process; count++) {
        faculty_Process[count].remaining = faculty_Process[count].burst_time;
        faculty_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;

    
    int flag, x, n, z, waiting_time = 0;
    do {
        for(count = 0; count < no_of_process; count++){
            if(total_time >= faculty_Process[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++; 
                    round_robin[queue] == count;
                }
            }
        }

        if(queue == 0) {
            n = 0;
        }
        if(faculty_Process[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(faculty_Process[n].remaining > 0) {
                if(faculty_Process[n].remaining < quantum_time){
                    total_time += faculty_Process[n].remaining;
                    faculty_Process[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    faculty_Process[n].remaining -= quantum_time;
                }
                faculty_Process[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;
        
        for(count = 0; count < no_of_process; count++) {
            if(faculty_Process[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);


    puts("\n\t\t\t********************************************");
    puts("\t\t\t**********   FACULTY QUERY OUTPUT   **********");
    puts("\t\t\t********************************************\n");
    printf("\n|\tProcess Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time\t |\tWaiting Time\t \n");

    for(count = 0; count < no_of_process; count++){
        waiting_time = faculty_Process[count].completion_time - faculty_Process[count].burst_time - faculty_Process[count].arrival_time;

        printf("\n|\t  %s\t          |\t  %d\t          |\t  %d\t         |\t  %d\t             |\t %d\t          \n", faculty_Process[count].process_name, faculty_Process[count].arrival_time, faculty_Process[count].burst_time, faculty_Process[count].completion_time, faculty_Process[count].waiting_time);
        printf("\nTotal time spent on handling queries: %d",total_time);
        avg_waiting=avg_waiting+(total_time/no_of_process);
        printf("\nAverage Query Time: %d",avg_waiting);
    }

}


void student(int no_of_process) {

    int count, arrival_Time, burst_Time, quantum_time;
    struct process_Struct student_Process[no_of_process];

    for(count = 0; count < no_of_process; count++) {
        printf("Enter the details of Process[%d]", count+1);
        puts("");
        printf("Process Name : ");
        scanf("%s", student_Process[count].process_name);

        printf("Arrival Time : ");
        scanf("%d", &student_Process[count].arrival_time);

        printf("Burst Time : ");
        scanf("%d", &student_Process[count].burst_time);
    }
    printf("Quantum time : ");
    scanf("%d", &quantum_time);


    for(count = 0; count < no_of_process; count++) {
        for(int x = count +1; x < count; x++){
            if(student_Process[count].arrival_time > student_Process[x].arrival_time) {
                temp_Struct = student_Process[count];
                student_Process[count] = student_Process[x];
                student_Process[x] = temp_Struct;
            }
        }
    }


    for(count = 0; count < no_of_process; count++) {
        student_Process[count].remaining = student_Process[count].burst_time;
        student_Process[count].completion_time = 0;
    }

    int total_time, queue, round_robin[20];
    total_time = 0;
    queue = 0;
    round_robin[queue] = 0;
    
    int flag, x, n, z, waiting_time = 0;
    float avg_waiting=0;
    do {
        for(count = 0; count < no_of_process; count++){
            if(total_time >= student_Process[count].arrival_time){
                z = 0;
                for(x = 0; x <= queue; x++) {
                    if(round_robin[x] == count) {
                        z++;
                    }
                }
                if(z == 0) {
                    queue++; 
                    round_robin[queue] == count;
                }
            }
        }

        if(queue == 0) {
            n = 0;
        }
        if(student_Process[n].remaining == 0) {
            n++ ;
        }
        if(n > queue) {
            n = (n - 1) % queue;
        }
        if(n <= queue) {
            if(student_Process[n].remaining > 0) {
                if(student_Process[n].remaining < quantum_time){
                    total_time += student_Process[n].remaining;
                    student_Process[n].remaining = 0;
                }else {
                    total_time += quantum_time;
                    student_Process[n].remaining -= quantum_time;
                }
                student_Process[n].completion_time = total_time;
            }
            n++;
        }
        flag = 0;
        
        for(count = 0; count < no_of_process; count++) {
            if(student_Process[count].remaining > 0) {
                flag++;
            }
        }
    }while(flag != 0);


    puts("\n\t\t\t********************************************");
    puts("\t\t\t**********   STUDENT QUERY OUTPUT   **********");
    puts("\t\t\t********************************************\n");
    printf("\n|\tProcess Name\t  |\tArrival Time\t  |\tBurst Time\t |\tCompletion Time\t |\tWaiting Time\t \n");

    for(count = 0; count < no_of_process; count++){
        waiting_time = student_Process[count].completion_time - student_Process[count].burst_time - student_Process[count].arrival_time;

        printf("\n|\t  %s\t          |\t  %d\t          |\t  %d\t         |\t  %d\t             |\t %d\t      \n", student_Process[count].process_name, student_Process[count].arrival_time, student_Process[count].burst_time, student_Process[count].completion_time, student_Process[count].waiting_time);
        printf("\nTotal time spent on handling queries: %d",total_time);
        avg_waiting=avg_waiting+(total_time/no_of_process);
        printf("\nAverage Query Time: %d",avg_waiting);
    }

}


int main(int argc, char const *argv[]) {
    int select_queue, no_of_process;

    puts(" Choose a queue to post your query : ");
    puts("1. FACULTY queue.");
    puts("2. STUDENT queue.");
    printf("> ");
    scanf("%d", &select_queue);

    switch(select_queue) {
        case 1 :
                printf("Enter number of process for FACULTY queue : ");
                scanf("%d", &no_of_process);
                
                faculty(no_of_process);
                
                break;

        case 2 :
                printf("Enter number of process for STUDENT queue : ");
                scanf("%d", &no_of_process);

                student(no_of_process);
                
                break;

        default : 
                printf("Please select the correct option.");
    }

    return 0;
}


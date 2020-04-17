#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};

struct car_parts
{
    int number_of_the_part;
    int number_of_the_parts_used;
    int sale_of_the_parts;
    struct car_parts * next_part;

};

struct car_of_the_man
{
    int number_of_the_car ;
    //int postion_of_the_car;
    char name_of_the_car[50] ;
    char color_of_the_car[50];
    char name_of_the_man_of_the_car[50];
    int number_of_the_man_of_the_car;
    struct car_of_the_man * next_car ;
};

struct car_maintenance
{
    int number_of_maintenance ;
    int number_of_the_car ;
    struct date date_of_the_maintenance;
    struct car_parts parts_of_car_need;
    int maintenance_fees;
    float total_cost ;
    struct car_maintenance * next_maintenance ;

};
struct car_of_the_man * new_car(int n)
{
    struct car_of_the_man * head = NULL;
    struct car_of_the_man * temp = NULL;
    struct car_of_the_man * position = NULL;
    int i=0;

    for(i=0;i<n;i++)
    {
        temp =(struct car_of_the_man *)malloc(sizeof(struct car_of_the_man));
        printf("\n enter number_of_the_car \n");
        scanf("%d",&(*temp).number_of_the_car);
        printf("\n enter name_of_the_car \n");
        scanf("%s",(*temp).name_of_the_car);
        printf("\n enter color_of_the_car \n");
        scanf("%s",(*temp).color_of_the_car);
        printf("\n enter name_of_the_man_of_the_car \n");
        scanf("%s",(*temp).name_of_the_man_of_the_car);
        printf("\n enter number_of_the_man_of_the_car \n");
        scanf("%d",&(*temp).number_of_the_man_of_the_car);
        (*temp).next_car = NULL ;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            position = head;
            while(((*position).next_car)!=NULL)
            {
                position = (*position).next_car;
            }
            (*position).next_car = temp;
        }

    }
    return head ;
}

void display_list_of_the_car (struct car_of_the_man * head)
{
    struct car_of_the_man * position;
    position = head;
    while(position != NULL )
    {
        printf("number_of_the_car : %d \n ",(*position).number_of_the_car);
        printf("name_of_the_car : %s \n",(*position).name_of_the_car);
        printf("color_of_the_car : %s \n",(*position).color_of_the_car);
        printf("name_of_the_man_of_the_car : %s \n",(*position).name_of_the_man_of_the_car);
        printf("number_of_the_man_of_the_car : %d \n",(*position).number_of_the_man_of_the_car);
        printf("------------------------------\n\n");
        position = (*position).next_car;
    }
}
void write_on_file (struct car_of_the_man * head , char * file_name)
{
    FILE * ptr_file;
    ptr_file = fopen(file_name,"w");
    struct car_of_the_man * position;
    position = head;
    while(position != NULL )
    {
        fprintf(ptr_file,"number_of_the_car : %d \n",(*position).number_of_the_car);
        fprintf(ptr_file,"name_of_the_car : %s \n",(*position).name_of_the_car);
        fprintf(ptr_file,"color_of_the_car : %s \n",(*position).color_of_the_car);
        fprintf(ptr_file,"name_of_the_man_of_the_car : %s \n",(*position).name_of_the_man_of_the_car);
        fprintf(ptr_file,"number_of_the_man_of_the_car : %d \n",(*position).number_of_the_man_of_the_car);
        fprintf(ptr_file,"------------------------------\n\n");
        position = (*position).next_car;
    }
    fclose(ptr_file);

}

void swap_car (struct car_of_the_man * p,struct car_of_the_man * q)
{
    int temp;
    char tempp[50];
    temp = (*p).number_of_the_car;
    (*p).number_of_the_car = (*q).number_of_the_car;
    (*q).number_of_the_car = temp;
    strcpy(tempp,(*p).name_of_the_car);
    strcpy((*p).name_of_the_car ,(*q).name_of_the_car);
    strcpy((*q).name_of_the_car ,tempp);
    strcpy(tempp , (*p).color_of_the_car);
    strcpy((*p).color_of_the_car ,(*q).color_of_the_car);
    strcpy((*q).color_of_the_car , tempp);
    strcpy(tempp , (*p).name_of_the_man_of_the_car);
    strcpy((*p).name_of_the_man_of_the_car ,(*q).name_of_the_man_of_the_car);
    strcpy((*q).name_of_the_man_of_the_car , tempp);
    temp = (*p).number_of_the_man_of_the_car;
    (*p).number_of_the_man_of_the_car = (*q).number_of_the_man_of_the_car;
    (*q).number_of_the_man_of_the_car = temp;
}

void sort_car_list (struct car_of_the_man * head , char * file_name)
{
    FILE * ptr_file;
    ptr_file = fopen(file_name,"w");
    struct car_of_the_man * p , * q;
    for(p = head ; (*p).next_car != NULL ; p = (*p).next_car)
    {
        for(q = (*p).next_car ; q != NULL ; q = (*q).next_car)
        {
            if ((*p).number_of_the_car > (*q).number_of_the_car)
            {
               swap_car(p,q);
            }
        }
    }
    write_on_file(head,file_name);
    fclose(ptr_file);

}

struct car_maintenance * new_car_maintenance(int num_maintenance , int num_car)
{
    struct car_maintenance * head = NULL;
    struct car_maintenance * temp = NULL;
    struct car_maintenance * position = NULL;
    int i=0;
    for(i=0;i<num_maintenance;i++)
    {
        temp = (struct car_maintenance *)malloc(sizeof(struct car_maintenance));
        printf("\n enter number_of_maintenance \n");
        scanf("%d",&(*temp).number_of_maintenance);
        (*temp).number_of_the_car = num_car;
        printf("\n enter maintenance_fees \n");
        scanf("%d",&(*temp).maintenance_fees);
        printf("\n to know the total_cost \n");
        printf("\n enter number_of_the_part (sire number) \n");
        scanf("%d",&(*temp).parts_of_car_need.number_of_the_part);
        printf("\n enter number_of_the_parts_used \n");
        scanf("%d",&(*temp).parts_of_car_need.number_of_the_parts_used);
        printf("\n enter sale_of_the_parts \n");
        scanf("%d",&(*temp).parts_of_car_need.sale_of_the_parts);
        (*temp).total_cost = ((*temp).parts_of_car_need.number_of_the_parts_used * (*temp).parts_of_car_need.sale_of_the_parts)+(*temp).maintenance_fees;
        printf("\n total cost : %f \n",(*temp).total_cost);
        printf("\n enter the date \n");
        printf("\n enter the day \n");
        scanf("%d",&(*temp).date_of_the_maintenance.day);
        printf("\n enter the month \n");
        scanf("%d",&(*temp).date_of_the_maintenance.month);
        printf("\n enter the year \n");
        scanf("%d",&(*temp).date_of_the_maintenance.year);
        (*temp).next_maintenance = NULL;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            position = head;
            while((*position).next_maintenance != NULL)
            {
                position = (*position).next_maintenance;
            }
            (*position).next_maintenance = temp;
        }
    }
    return head ;
}

void display_list_of_the_maintenance_file_conslole(struct car_maintenance * head , char * file_name)
{
    struct car_maintenance * position ;
    position = head ;
    FILE * ptr_file;
    ptr_file = fopen(file_name,"a");
    while (position != NULL)
    {
        fprintf(ptr_file,"\n number_of_maintenance : %d ",(*position).number_of_maintenance);
        fprintf(ptr_file,"\n number_of_the_car : %d ",(*position).number_of_the_car);
        fprintf(ptr_file,"\n number_of_the_part (sire number) : %d",(*position).parts_of_car_need.number_of_the_part);
        fprintf(ptr_file,"\n number_of_the_parts_used : %d",(*position).parts_of_car_need.number_of_the_parts_used);
        fprintf(ptr_file,"\n sale_of_the_parts : %d",(*position).parts_of_car_need.sale_of_the_parts);
        fprintf(ptr_file,"\n total_cost : %.1f",(*position).total_cost);
        fprintf(ptr_file,"\n the date is d/m/y : %d/%d/%d \n",(*position).date_of_the_maintenance.day,(*position).date_of_the_maintenance.month,(*position).date_of_the_maintenance.year);
        fprintf(ptr_file,"----------------------------------------");
        printf("\n number_of_maintenance : %d ",(*position).number_of_maintenance);
        printf("\n number_of_the_car : %d ",(*position).number_of_the_car);
        printf("\n number_of_the_part (sire number) : %d",(*position).parts_of_car_need.number_of_the_part);
        printf("\n number_of_the_parts_used : %d",(*position).parts_of_car_need.number_of_the_parts_used);
        printf("\n sale_of_the_parts : %d",(*position).parts_of_car_need.sale_of_the_parts);
        printf("\n total_cost : %.1f",(*position).total_cost);
        printf("\n the date is d/m/y : %d/%d/%d \n",(*position).date_of_the_maintenance.day,(*position).date_of_the_maintenance.month,(*position).date_of_the_maintenance.year);
        printf("----------------------------------------");
        position = (*position).next_maintenance;
    }
    fclose(ptr_file);
}

struct car_of_the_man * delete_car (struct car_of_the_man * head_car , int car_num)
{
    struct car_of_the_man *p ,*q ;
    if(car_num == (*head_car).number_of_the_car)
    {
        p = head_car;
        head_car = (*head_car).next_car;
        free(p);
    }
    else
    {
        p = q =head_car;
        while((*p).number_of_the_car != car_num)
        {
            q = p;
            p = (*p).next_car;
        }
        (*q).next_car = (*p).next_car;
        free(p);
    }
    return head_car ;

}

void search_car_man (struct car_of_the_man * head , char * search_name)
{
    struct car_of_the_man * p;
    p=head;
    while(p!=NULL)
    {
        if((strcmp(search_name,(*p).name_of_the_man_of_the_car))==0)
        {
            printf("\n his number car : %d \t his name car : %s \n",(*p).number_of_the_car ,(*p).name_of_the_car);
        }
        p = (*p).next_car;
    }


}

void switch_maintenance (struct car_maintenance *p , struct car_maintenance * q)
{
    int temp ;
    temp = (*p).number_of_maintenance;
    (*p).number_of_maintenance = (*q).number_of_maintenance;
    (*q).number_of_maintenance = temp;
    temp = (*p).number_of_the_car;
    (*p).number_of_the_car = (*q).number_of_the_car;
    (*q).number_of_the_car = temp ;
    temp = (*p).date_of_the_maintenance.day;
    (*p).date_of_the_maintenance.day = (*q).date_of_the_maintenance.day;
    (*q).date_of_the_maintenance.day = temp;
    temp = (*p).date_of_the_maintenance.month;
    (*p).date_of_the_maintenance.month = (*q).date_of_the_maintenance.month;
    (*q).date_of_the_maintenance.month = temp;
    temp = (*p).date_of_the_maintenance.year;
    (*p).date_of_the_maintenance.year = (*q).date_of_the_maintenance.year;
    (*q).date_of_the_maintenance.year = temp;
    temp = (*p).parts_of_car_need.number_of_the_part;
    (*p).parts_of_car_need.number_of_the_part = (*q).parts_of_car_need.number_of_the_part;
    (*q).parts_of_car_need.number_of_the_part = temp;
    temp = (*p).parts_of_car_need.number_of_the_parts_used;
    (*p).parts_of_car_need.number_of_the_parts_used = (*q).parts_of_car_need.number_of_the_parts_used;
    (*q).parts_of_car_need.number_of_the_parts_used = temp;
    temp = (*p).parts_of_car_need.sale_of_the_parts;
    (*p).parts_of_car_need.sale_of_the_parts = (*q).parts_of_car_need.sale_of_the_parts;
    (*q).parts_of_car_need.sale_of_the_parts = temp ;
    temp = (*p).maintenance_fees;
    (*p).maintenance_fees = (*q).maintenance_fees;
    (*q).maintenance_fees = temp;
    temp = (*p).total_cost;
    (*p).total_cost = (*q).total_cost;
    (*q).total_cost = temp;

}

void sort_maintenance_list (struct car_maintenance * head )
{
    struct car_maintenance *p ,*q;
    for(p=head ; (*p).next_maintenance != NULL ;p=(*p).next_maintenance)
    {
        for(q=(*p).next_maintenance ; q!=NULL ;q=(*q).next_maintenance)
        {
            if((*p).number_of_maintenance > (*q).number_of_maintenance)
            {
                switch_maintenance(p,q);
            }
        }
    }
}

void private_car_display (struct car_maintenance * head , int num_car )
{
    struct car_maintenance * p;
    float total = 0;
    p = head ;
    while (p != NULL)
    {
        printf("\n\n\t%d\n",(*p).number_of_the_car);
        if((*p).number_of_the_car == num_car)
        {
            printf("\nnpp\n");
            printf("\n number_of_maintenance : %d ",(*p).number_of_maintenance);
            printf("\n number_of_the_car : %d ",(*p).number_of_the_car);
            printf("\n number_of_the_part (sire number) : %d",(*p).parts_of_car_need.number_of_the_part);
            printf("\n number_of_the_parts_used : %d",(*p).parts_of_car_need.number_of_the_parts_used);
            printf("\n sale_of_the_parts : %d",(*p).parts_of_car_need.sale_of_the_parts);
            printf("\n total_cost : %.1f",(*p).total_cost);
            printf("\n the date is d/m/y : %d/%d/%d \n",(*p).date_of_the_maintenance.day,(*p).date_of_the_maintenance.month,(*p).date_of_the_maintenance.year);
            printf("----------------------------------------\n");
            total +=(*p).total_cost;
        }
        p = (*p).next_maintenance;
    }
    printf("\n\n the final cost is : %.1f \n",total);
}

struct car_maintenance * concatenate (struct car_maintenance * head1 , struct car_maintenance * head2)
{
    struct car_maintenance *p;
    p = NULL;
    if ( head1 == NULL)
    {
        return head2 ;
    }
    if ( head2 == NULL)
    {
        return head1;
    }
    p = head1;
    while((*p).next_maintenance != NULL)
    {
        p = (*p).next_maintenance;
    }
    (*p).next_maintenance = head2 ;
    return head1;
}

struct car_parts * more_used (struct car_maintenance * head )
{
    struct car_maintenance * p;
    struct car_parts * head_car_part = NULL;
    struct car_parts * position = NULL;
    struct car_parts * temp = NULL;

    for(p = head ; p!=NULL ;p=(*p).next_maintenance)
    {
        temp = (struct car_parts * )malloc(sizeof(struct car_parts));
        (*temp).number_of_the_part = (*p).parts_of_car_need.number_of_the_part;
        (*temp).number_of_the_parts_used =(*p).parts_of_car_need.number_of_the_parts_used;
        (*temp).next_part = NULL;
        if(head_car_part == NULL)
        {
            head_car_part = temp;
            printf("\n...gfgfg....\n");
        }
        else
        {
             printf("\n...gfgfg....\n");
            position = head_car_part;
            while(position != NULL && (*temp).number_of_the_part != 0)
            {
                printf("\n \t\t the used : %d temp %d\n",(*position).number_of_the_part,(*temp).number_of_the_part);
                if((*position).number_of_the_part == (*temp).number_of_the_part)
                {
                    printf("\n...gfgfg....\n");
                    (*position).number_of_the_parts_used += (*temp).number_of_the_parts_used;
                    (*temp).number_of_the_part = 0;
                }
                else
                {
                    printf("\n...gfgfg....\n");
                    position = (*position).next_part;
                }
            }
            if((*temp).number_of_the_part == 0)
            {
                (*position).next_part = temp;
                printf("\n...gfgfg....\n");
            }
        }
    }
    return head_car_part ;
}

struct car_parts * max_number ( struct car_parts * head_car_part)
{
    struct car_parts * position, * next_position;
    int temp;
    position = head_car_part;
    for(position = head_car_part ; (*position).next_part != NULL ; position = (*position).next_part)
    {
        for(next_position = (*position).next_part;next_position!=NULL;next_position=(*next_position).next_part)
        {
            if((*position).number_of_the_parts_used < (*next_position).number_of_the_parts_used)
            {
                temp = (*position).number_of_the_part;
                (*position).number_of_the_part = (*next_position).number_of_the_part;
                (*next_position).number_of_the_part = temp;
                temp = (*position).number_of_the_parts_used;
                (*position).number_of_the_parts_used = (*next_position).number_of_the_parts_used;
                (*next_position).number_of_the_parts_used = temp;
            }
        }
    }
    return head_car_part;
}



void display_date(struct car_maintenance * head)
{
    struct car_maintenance * p ;
    int day,month,year;
    printf("\n what is the date you want to the maintenance after it \n");
    printf("\n enter the day :  \n");
    scanf("%d",&day);
    printf("\n enter the month :  \n");
    scanf("%d",&month);
    printf("\n enter the year :  \n");
    scanf("%d",&year);
    for(p = head ; p != NULL ; p=(*p).next_maintenance)
    {
        if((*p).date_of_the_maintenance.year > year)
        {
            printf("the car is : %d",(*p).number_of_the_car);
        }
        else if((*p).date_of_the_maintenance.year == year)
        {
            if((*p).date_of_the_maintenance.month > month)
            {
                printf("the car is : %d",(*p).number_of_the_car);
            }
            else if((*p).date_of_the_maintenance.month == month)
            {
                if((*p).date_of_the_maintenance.day > day)
                {
                    printf("\nthe car is : %d\n",(*p).number_of_the_car);
                    printf("\n the number of maintenance is : %d \n",(*p).number_of_maintenance);
                }
            }
        }
    }
}

void display_car_wheels(struct car_maintenance * head , struct car_of_the_man * head2 , int wheels)
{
    struct car_maintenance *p1;
    struct car_of_the_man *p2;
    p1 = head ;
    p2 = head2;
    while(p2!= NULL)
    {
        while(p1 != NULL)
        {
            if((*p1).parts_of_car_need.number_of_the_part == wheels)
                {
                    printf("\n the car whom used wheels is : %s\n",(*p2).name_of_the_car);
                }
            p1 = (*p1).next_maintenance;
        }
        p2 = (*p2).next_car;
    }
}

int main()
{
    FILE * car_file;
    car_file = fopen("car_man.txt","w");
    int loop=0,num_to_know=0;
    int wheels;
    struct car_of_the_man * head_car ;
    struct car_maintenance * head_maintenance1, * head_maintenance2;
    struct car_parts temp;
    struct car_parts * head_car_part;
    int number_of_new_car , car_to_maintenance, delete_position=0;
    char name_man[50];
    printf("\n enter the number of new car you want add \n\n");
    scanf("%d",&number_of_new_car);
    head_car = new_car(number_of_new_car);
    //display_list_of_the_car(head);
    sort_car_list(head_car,"car_man.txt");
    display_list_of_the_car(head_car);
    printf("\n enter the car you want to take it to maintenance \n ");
    scanf("%d",&car_to_maintenance);
    printf("\n how maintenance you did on this car ?? \n");
    scanf("%d",&number_of_new_car);
    head_maintenance1 = new_car_maintenance(number_of_new_car , car_to_maintenance);
    //display_list_of_the_maintenance_file_conslole(head_maintenance ,"maintenance_car.txt");
    /*printf("\n if you want too add new maintenance press 1 \n");
    scanf("%d",&loop);
    if(loop == 1)
    {
        printf("\n enter the car you want to take it to maintenance \n ");
        scanf("%d",&car_to_maintenance);
        printf("\n how maintenance you did on this car ?? \n");
        scanf("%d",&number_of_new_car);
        head_maintenance2 = new_car_maintenance(number_of_new_car , car_to_maintenance);
    }
    head_maintenance1 = concatenate(head_maintenance1 , head_maintenance2);
    */
    //printf("\n enter the position to delete \n");
    //scanf("%d",&delete_position);
    //head_car = delete_car(head_car , delete_position);
    //display_list_of_the_car(head_car);
    //printf("\n enter name of the man to search on \n");
    //scanf("%s",name_man);
    //search_car_man(head_car,name_man);
    //sort_maintenance_list(head_maintenance);
    //display_list_of_the_maintenance_file_conslole(head_maintenance,"maintenance_car.txt");
    //printf("\n enter the number of a car to see it maintenance \n");
    //scanf("%d",&num_to_know);
    //private_car_display(head_maintenance1 , num_to_know);
    //temp = more_used(head_maintenance1);
    //display_date(head_maintenance1);
    printf("\n enter the number of wheels :\n ");
    //scanf("%d",&wheels);
    //display_car_wheels(head_maintenance1 , head_car ,wheels);
    head_car_part = more_used(head_maintenance1);
    head_car_part = max_number(head_car_part);
    printf("\nthe most used is :  %d\n",(*head_car_part).number_of_the_part);
    printf("\nthe most used is :  %d\n",(*head_car_part).number_of_the_parts_used);
    return 0;
}

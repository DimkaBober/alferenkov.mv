#include "array_utills.h"


void menu(){
    printf("\nВыберите операцию:\n");
    printf("1 - Инициализация массива\n");
    printf("2 - Вставка нового элемента\n");
    printf("3 - Удаление элемента\n");
    printf("4 - Индивидуальное задание (удаление дубликатов)\n");
    printf("5 - Вывод содержимого массива\n\n");
}

int main(){
    int choise, check, index, value, last;
    size_t size;
	while(1){
    	printf("Введите длину массива: ");
    	check = scanf("%zu", &size);
    	if (check == EOF) {
	        printf("Ввод прерван пользователем\n");
	        return 0;
        }
        else if(check == 0){
        	printf("Некорректный ввод\n");
        	while(getchar() != '\n');
        	continue;
        }
        break;
    }  
    int *mas = inicialize_mas(size);
    print_mas(mas, size);

    while(1){
        menu();
        printf("\nВведите номер операции: ");
        check = scanf("%d", &choise);
    	if (check == EOF) {
	        printf("Ввод прерван пользователем\n");
	        return 0;
        }
        else if(check == 0){
        	printf("Некорректный ввод\n");
        	while(getchar() != '\n');
        	continue;
        }       
        switch (choise) {
            case 1:
            	last = size;
            	while(1){
	                printf("\nВведите длину инициализируемого массива: ");
	                check = scanf("%zu", &size);
	    			if (check == EOF) {
		        		printf("Ввод прерван пользователем\n");
		        		return 0;
	        		}
			        else if(check == 0){
			        	printf("Некорректный ввод\n");
			        	while(getchar() != '\n');
	        			continue;
	        		}
	        		break;
	        	}           
                free(mas);
                mas = inicialize_mas(size);
                if (mas == NULL) {
                    printf("Ошибка инициализации\n");
                    continue;
                }
                break;
           /* case 2:
                index = get_input_int("Введите индекс для нового элемента: ", &flag, index);
                if (flag == false) {
                    printf("Ввод прерван пользователем\n");
                    flag = true;
                    continue;
                }
                value = get_input_int("Введите элемент, который хотите добавить: ", &flag, value);
                if (flag == false) {
                    printf("Ввод прерван пользователем\n");
                    flag = true;
                    continue;
                }
                check = add_elem(&mas, &size, index, value);
                if (check == 0) {
                    printf("Элемент %d добавлен на позицию %d\n", value, index);
                }
                if (check == 1) {
                    printf("Неверный индекс!\n");
                    continue;
                } else if (check == 2) {
                    printf("Ошибка выделения памяти!\n");
                    continue;
                } else if (check == 3) {
                    printf("Индекс больше длины массива, Элемент %d добавлен в конец\n", value);
                }
                break;
            case 3:
                index = get_input_int("Введите индекс элемента, который хотите удалить: ", &flag, index);
                if (flag == false) {
                    printf("Ввод прерван пользователем\n");
                    flag = true;
                    continue;
                } 
                check = del_elem(&mas, &size, index);
                if (check == 0) {
                    printf("Элемент с индексом %d удален\n", index);
                }
                else if (check == 1) {
                    printf("Неверный индекс!\n");
                } else if (check == 2) {
                    printf("Ошибка выделения памяти!\n");
                    continue;
                }
                break;
            case 4:
                {
                    int *new_mas = NULL;
                    size_t new_size = 0;
                    remove_non_unique(mas, &size, &new_mas, &new_size);
                    printf("Массив после удаления не уникальных элементов: ");
                    print_mas(mas, size);
                    printf("Не уникальные элементы: ");
                    print_mas(new_mas, new_size);
                    free(new_mas);
                }
                continue;
            case 5:
                print_mas(mas, size);
                continue;*/
            default:
                printf("Некорректный ввод\n");
        }
        print_mas(mas, size);
    }

    free(mas);
    return 0;
}

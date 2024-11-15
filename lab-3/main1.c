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
    int choise, check, index, value;
    size_t size;
    printf("\nВведите длину инициализируемого массива: ");
    check = scanf("%zu", &size);
    if(check == EOF) return 0;
    if (check == 0){
        printf("Некорректный ввод данных\n");
        while(getchar() != '\n');
        main();
    }
    int *mas = inicialize_mas(size);
    print_mas(mas, size);
    while(1){
        menu();
        printf("\nВведите номер операции: ");
        check = scanf("%d", &choise);
        if(check == EOF){
  			free(mas);
            return 0;
        }
        else if(check == 0){
        	printf("Некорректный ввод данных\n");
            while(getchar() != '\n');
            continue;
        }
        switch (choise) {
            case 1:
            	while(1){
	                printf("Введите длину инициализируемого массива\n");
	                check = scanf("%zu", &size);
	                if(check == EOF){
	                	free(mas);
	                	return 0;	
	                }
	                if (check == 0){
	                    printf("Некорректный ввод данных\n");
	                    while(getchar() != '\n');
	                    continue;
	                }
	                break;
	            }
                free(mas);
                mas = inicialize_mas(size);
                if(mas == NULL){
                    printf("Ошибка инициализации\n");
                    free(mas);
                    continue;
                }
                print_mas(mas, size);
                break;
            case 2:
            	while(1){
	                printf("Введите индекс для нового элемента\n");
	                check = scanf("%d", &index);
	                if(check == EOF){
	                	free(mas);
	                	return 0;
	                }
	                if (check == 0){
	                    printf("Некорректный ввод данных\n");
	                    while(getchar() != '\n');
	                    continue;
	                }
	                break;
	            }
	            while(1){
	                printf("Введите элемент который хотите добавить\n");
	                check = scanf("%d", &value);
	                if(check == EOF){
	                	free(mas);
	                	return 0;
	                }
	                if (check == 0){
	                    printf("Некорректный ввод данных\n");
	                    while(getchar() != '\n');
	                    continue;
	                }
	                break;
	            }
                check = add_elem(&mas, &size, index, value);
                if(check == 0){
                    printf("Элемент %d добавлен на позицию %d", value, index);
                }
                else if(check == 1){
                	printf("Неверный индекс\n");
                }
                else if(check == 2){
                	printf("Ошибка выделения памяти\n");
                }
                else if(check == 3){
                    printf("Индекс больше длины массива, Элемент %d добавлен в конец", value);
                }
                break;
            case 3:
            	while(1){
	                printf("Введите индекс элемента который хотите удалить\n");
	                check = scanf("%d", &index);
	                if(check == EOF){
	                	free(mas);
	                	return 0;
	                }
	                if (check == 0){
	                    printf("Некорректный ввод данных\n");
	                    while(getchar() != '\n');
	                    continue;
	                }
	                break;
	            }
                check = del_elem(&mas, &size, index);
                if(check == 0){
                    printf("Элемент с индексом %d добавлен удален", index);
                }
                else if(check == 1){
                	printf("Неверный индекс\n");
                }                
                break;
            case 4:
                int *new_mas = NULL;
                size_t new_size = 0;
                check = remove_non_unique(mas, &size, &new_mas, &new_size);
                if(check == 1){
                   	printf("Ошибка выделения памяти для подсчета частоты!\n");
                }
                else if(check == 2){
                    printf("Ошибка выделения памяти для нового массива!\n");
                }
                
                printf("Массив после удаления не уникальных элементов: ");
                print_mas(mas, size);
                printf("Не уникальные элементы: ");
                print_mas(new_mas, new_size);
                free(new_mas);
                continue;
            case 5:
                print_mas(mas, size);
                continue;
            default:
                printf("Некорректный ввод\n");
        }
        print_mas(mas, size);
    }
    
    free(mas);
    return 0;
}

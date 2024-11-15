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
    int choise, check, index, value, size;
    bool flag_exit = true;
    while(1){	
    	printf("Введите длину инициализируемого массива: ");
	    check = input(&size);
	    if(check == 3){
	    	printf("Ввод прерван пользователем\n");
	   		return 0;
	   	}
	    if (check == 1){
	        printf("Некорректный ввод данных\n");
	        continue;
	    }
	    break;
	}
    int *mas = inicialize_mas(size);
    if (mas == NULL){
    	printf("Ошибка инициализации\n");
    	size = 0;
    }
    completion_mas(mas, size);
    print_mas(mas, size);
    while(1){
    	flag_exit = true;
        menu();
        while(1){	
            printf("\nВведите номер операции: ");
	    	check = input(&choise);
		    if(check == 3){
		    	printf("Ввод прерван пользователем\n");
		   		return 0;
		   	}
		    if (check == 1){
		        printf("Некорректный ввод данных\n");
		        continue;
		    }
		    break;
		}
        switch (choise) {
            case 1:
				while(1){	
			        printf("Введите длину инициализируемого массива: ");
			    	check = input(&size);
				    if(check == 3){
				    	printf("Ввод прерван пользователем\n");
				   		flag_exit = false;
				   		break;
				   	}
				    if (check == 1){
				        printf("Некорректный ввод данных\n");
				        continue;
				    }
				    break;
				}
				if(!flag_exit) continue;
                free(mas);
                mas = inicialize_mas(size);
                if(mas == NULL){
                    printf("Ошибка инициализации\n");
                    free(mas);
                    continue;
                }
                completion_mas(mas, size);
                break;
          case 2:
				while(1){	
			        printf("Введите индекс для нового элемента\n");
			    	check = input(&index);
				    if(check == 3){
				    	printf("Ввод прерван пользователем\n");
				   		flag_exit = false;
				   		break;
				   	}
				    if (check == 1){
				        printf("Некорректный ввод данных\n");
				        continue;
				    }
				    break;
				}
				if(!flag_exit) continue;
				while(1){	
			        printf("Введите элемент который хотите добавить\n");
			    	check = input(&value);
				    if(check == 3){
				    	printf("Ввод прерван пользователем\n");
				   		flag_exit = false;
				   		break;
				   	}
				    if (check == 1){
				        printf("Некорректный ввод данных\n");
				        continue;
				    }
				    break;
				}
	            if(!flag_exit) continue;
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
			    	check = input(&index);
				    if(check == 3){
				    	printf("Ввод прерван пользователем\n");
				   		flag_exit = false;
				   		break;
				   	}
				    if (check == 1){
				        printf("Некорректный ввод данных\n");
				        continue;
				    }
				    break;
				}
				if(!flag_exit) continue;
                check = del_elem(&mas, &size, index);
                if(check == 0){
                    printf("Элемент с индексом %d удален", index);
                }
                else if(check == 1){
                	printf("Неверный индекс\n");
                }                
                break;
           case 4:
                int *new_mas = NULL;
                int new_size = 0;
				check = remove_non_unique(&mas, &size, &new_mas, &new_size);
    			if (check == 0) {
    	        	printf("Массив после удаления не уникальных элементов: ");
    	            print_mas(mas, size);
    	            printf("Не уникальные элементы: ");
    	            print_mas(new_mas, new_size);
    	        } else {
    	            printf("Ошибка при обработке массива!\n");
    	        }
				free(new_mas);  // Освобождаем память для нового массива
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int chooseLanguage() {

    int choice;

    printf("************** Welcome to the ATM **************\n");
    printf("1. English\n");
    printf("2. French\n");
    printf("3. Spanish\n");
    printf("Please select prefered language: ");
    scanf("%d", &choice);

    return choice;
}

void displayMenu(int chooseLang) {
    switch(chooseLang) {
        case 1:
            printf("************** Welcome to the ATM **************\n");
            printf("1. Check Balance\n");
            printf("2. Deposit\n");
            printf("3. Withdraw\n");
            printf("4. Transfer\n");
            printf("5. Credit\n");
            printf("6. Exit\n");
            printf("Please enter your choice: ");

            break;

        case 2: 
            printf("************** Bienvenue à l'ATM **************\n");
            printf("1. Vérifier le solde\n");
            printf("2. Déposer\n");
            printf("3. Retirer\n");
            printf("4. Transférer\n");
            printf("5. Crédit\n");
            printf("6. Sortie\n");
            printf("Veuillez entrer votre choix: ");

            break;

        case 3:
            printf("************** Bienvenido al cajero automático **************\n");
            printf("1. Verificar saldo\n");
            printf("2. Depositar\n");
            printf("3. Retirar\n");
            printf("4. Transferir\n");
            printf("5. Crédito\n");
            printf("6. Salida\n");
            printf("Por favor ingrese su elección: ");

            break;

    }
}

void processingDisplay(int chooseLang, int j) {
    switch(chooseLang) {
        case 1:
            if(j == 2) {
                printf("Please enter the amount you want to deposit: ");
            }

            else if(j == 3) {
                printf("Please enter the amount you want to withdraw: ");
            }

            else if(j == 4) {
                printf("Please enter the user to transfer to: ");
            }

            else if(j == 5) {
                printf("The amount should not be less than Rs. 50\n");
                printf("Please enter the amount you want to credit: ");
            }

            else if(j == 6) {
                printf("Thank you for using the ATM.\n");
            }

            break;  

        case 2: 
            if(j == 2) {
                printf("Veuillez saisir le montant que vous souhaitez déposer: ");
            }

            else if(j == 3) {
                printf("Veuillez saisir le montant que vous souhaitez retirer: ");
            }

            else if(j == 4) {
                printf("Veuillez saisir le nom de l'utilisateur à transférer: ");
            }

            else if(j == 5) {
                printf("Le montant ne doit pas être inférieur à Rs. 50\n");
                printf("Veuillez saisir le montant que vous souhaitez créditer: ");
            }

            else if(j == 6) {
                printf("Merci d'avoir utilisé le guichet automatique.\n");
            }

            break;

        case 3:
            if(j == 2) {
                printf("Introduzca el importe que desea ingresar: ");
            }

            else if(j == 3) {
                printf("Introduzca el importe que desea retirar: ");
            }

            else if(j == 4) {
                printf("Introduzca el usuario al que desea transferir : ");
            }

            else if(j == 5) {
                printf("El importe no debe ser inferior a Rs. 50\n");
                printf("Por favor ingrese el monto que desea acreditar: ");
            }

            else if(j ==6) {
                printf("Gracias por utilizar el cajero automático.\n");
            }

            break; 

    }
}

void language(int chooseLang) {
    switch(chooseLang) {
        case 1:
            printf("Please enter your username: ");
            break;
        case 2:
            printf("S'il vous plait entrer votre nom d'utilisateur: ");
            break;
        case 3:
            printf("Por favor ingrese su nombre de usuario: ");
            break;
        default:
            printf("Please enter your username: ");
            break;
    }
}

void checkBalance(float balance) {
    printf("Your balance is Rs. %.2f\n", balance);
}

float deposit(float balance, float amount) {
    balance += amount;
    printf("Rs. %.2f has been deposit into your account. Your new balance is Rs. %.2f\n", amount, balance);

    return balance;
}

float withdraw(float balance, float amount) {
    if(balance < amount) {
        printf("Insufficient funds.\nYour balance is Rs. %.2f\n", balance);
    }

    else {
        balance -= amount;
        printf("Rs. %.2f has been withdrawn from your account.\nYour new balance is Rs. %.2f\n", amount, balance);     
    }

    return balance;
}

float transfer(float balance, float amount, float *target_balance) {
    if(balance < amount) {
        printf("Insufficient funds.\nYour balance is Rs. %.2f\n", balance);
    }

    else {
        balance -= amount;
        *target_balance += amount;
    }

    return balance;
}

float credit(float balance, float amount, float verification_balance) {
    verification_balance = 0.3 * balance;

    if(verification_balance < amount) {
        printf("Elagible for credit");
    }

    else {
        balance += amount;
        printf("Rs. %.2f has been credited to your account.\nYour new balance is Rs. %.2f\n", amount, balance);     
    }

    return balance;
    
}

int main()
{

        
    while(1) {

        char username[50], input[50], target_username[50], searched_username[50];
        int pin, input_pin, i, j, chooseLang;
        float balance, amount, target_balance, verification_balance;

        FILE * user_data;
        FILE * temp_file;

        user_data = fopen("user_data.txt", "r");
        temp_file = fopen("temp_file.txt", "w");

        

        chooseLang = chooseLanguage();
        language(chooseLang);

        scanf("%s", &input);

        while(fscanf(user_data, "%s %d %f", &username, &pin, &balance) != EOF) {
            if(strcmp(input, username) == 0) {
                                
                do{

                    printf("Please enter your pin: ");
                    scanf("%d", &input_pin);
                    if(input_pin == pin) {
                        while(1) {

                            displayMenu(chooseLang);
                            scanf("%d", &j);
                            
                            switch(j) {
                                case 1:
                                    checkBalance(balance);
                                    break;
                                case 2:
                                    processingDisplay(chooseLang, j);
                                    scanf("%f", &amount);
                                    balance = deposit(balance, amount);
                                    break;
                                case 3:
                                    processingDisplay(chooseLang, j);
                                    scanf("%f", &amount);
                                    balance = withdraw(balance, amount);
                                    break;

                                case 4:
                                    processingDisplay(chooseLang, j);
                                    scanf("%s", &target_username);

                                    if(strcmp(target_username, username) == 0) {
                                        printf("You cannot transfer to yourself.\n");
                                        break;
                                    }
                                    
                                    else if(strcmp(target_username, "6") == 0) {
                                        break;
                                    }

                                    else {

                                        printf("Please enter the amount you want to transfer: ");
                                        scanf("%f", &amount);
                                        while(fscanf(user_data, "%s %d %f", &searched_username, &pin, &target_balance) != EOF) {
                                            
                                            if(strcmp(target_username, searched_username) == 0) {

                                                balance = transfer(balance, amount, &target_balance);

                                                printf("Rs. %.2f has been transfered to %s's account.\n", amount, target_username); 
                                                break;
                                            }                                                                              

                                        }

                                    }

                                case 5:

                                    processingDisplay(chooseLang, j);

                                    scanf("%f", &amount);

                                    if(amount < 50 && amount != 6) {
                                        printf("The amount should not be less than Rs. 50\n");
                                        break;
                                    }

                                    else if(amount == 6) {
                                        break;
                                    }

                                    else {

                                        balance = credit(balance, amount, verification_balance);
                                        break;

                                    }                                    
                                
                                case 6:
                                    processingDisplay(chooseLang, j);
                                    break;
                                
                            }

                            
                            if(j == 6) {
                                break;
                            }
                        }
                    }
                    else {
                        printf("Incorrect pin.\n");
                        printf("You have %d attempts left.\n", 3 - i);
                        i++;
                    }

                                        
                    if(j == 6) {
                        break;
                    }
                }
                while(i != 4);
            }
            fprintf(temp_file, "%s %d %.2f\n", username, pin, balance);
        }

        fclose(user_data);
        fclose(temp_file);

        if(j == 6) {

            remove("user_data.txt");
            rename("temp_file.txt", "user_data.txt");

            break;
        }
    }
    return 0;
}

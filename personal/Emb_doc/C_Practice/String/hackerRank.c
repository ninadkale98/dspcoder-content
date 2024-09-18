#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPHS 5
#define MAX_CHARACTERS 1005

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};


struct document give_doc(char text[]){
    struct document Doc ; 

    Doc.paragraph_count = 1; 
    Doc.data = (struct paragraph* )malloc( sizeof(struct paragraph*) * 5 ); 
    

    Doc.data->sentence_count = 1; 
    Doc.data->data = (struct sentence* )malloc( sizeof(struct sentence*)); 

    Doc.data->data->word_count = 1; 
    Doc.data->data->data = (struct word* )malloc( sizeof(struct word*)); 

    Doc.data->data->data->data = (char* )malloc( sizeof(char*)); 

    int len = strlen(text); 
    int para_count = 0;
    int sen_count = 0;  
    int word_count = 0; 
    int char_count = 0; 

    for(int i = 0; i < len; i++){
        
        if(isalpha(text[i])){
            char *add = &Doc.data[para_count].data[sen_count].data[word_count].data[char_count]; 
            struct word *add_word = &Doc.data[para_count].data[sen_count].data[word_count]; 

            Doc.data[para_count].data[sen_count].data[word_count].data[char_count] = text[i]; 
            char_count += 1; 

            // char * char_with_updated_size = (char* ) realloc(Doc.data[para_count].data[sen_count].data[word_count].data , (char_count+1)* sizeof(char*)); 
            Doc.data[para_count].data[sen_count].data[word_count].data = (char* ) realloc(Doc.data[para_count].data[sen_count].data[word_count].data , (char_count+1)* sizeof(char*));  //char_with_updated_size ; 
        }

        else if(text[i] == ' '){
            char_count = 0; 
            word_count += 1; 

            int size = sizeof(Doc.data[para_count].data[sen_count].data)/sizeof(struct word* );
            Doc.data[para_count].data[sen_count].data = (struct word* ) realloc(Doc.data[para_count].data[sen_count].data , (word_count + 1)* sizeof(struct word));
            size = sizeof(Doc.data[para_count].data[sen_count].data)/sizeof(struct word* );
            
        }

        else if(text[i] == '.'){
            char_count = 0;
            word_count = 0;
            sen_count += 1; 

            int size = sizeof(Doc.data[para_count].data)/sizeof(struct sentence* );
            Doc.data[para_count].data = (struct sentence* ) realloc(Doc.data[para_count].data , (sen_count + 1)* sizeof(struct sentence));
            size = sizeof(Doc.data[para_count].data)/sizeof(struct sentence* );
        }
        
        else if(text[i] == '\n'){
            char_count = 0;
            word_count = 0;
            sen_count = 0; 
            para_count += 1; 

            int size = sizeof(Doc.data)/sizeof(struct paragraph* );
            Doc.data = (struct paragraph* ) realloc(Doc.data , (para_count + 1)* sizeof(struct paragraph));
            size = sizeof(Doc.data)/sizeof(struct paragraph* );

        }

    }

    return Doc; 

}


int main(){
    char *s = "Hi ho. Wo u \n I a f.";

    struct document Doc = give_doc(s); 
    


    return 0; 
}


// int number_of_paragraph(char text[]){
//     int len = strlen(text); 
//     int count = 1;
//     for(int i = 0; i < len ; i ++){
//         if(text[i] == '\n'){
//             count += 1;
//         }
//     }
//     return count;
    
// }


// struct document give_doc(char text[]){
    
//     struct document Doc ; 
//     int len = strlen(text); 

//     int no_of_paras = number_of_paragraph(text); 
//     Doc.data = (struct paragraph*)malloc(sizeof(struct paragraph) * no_of_paras); 

//     int para_start_index = 0; 
    
//     for(int i = 0; i < no_of_paras ; i ++){

//         int no_of_sentences = 0 ; 

//         for(int j = para_start_index ; j < len ; j ++ ){
//             if(text[j] == '\n'){
//                 para_start_index = j+1; 
//                 break; 
//             }
//             if(text[j] == '.'){
//                 no_of_sentences += 1;
//             }
//         }

//         Doc.data[i].sentence_count = no_of_sentences; 
//         Doc.data[i].data = (struct sentence*) malloc(sizeof(struct sentence*)*no_of_sentences); 

//         for(int j = 0; j < no_of_sentences ; j++){
            
//         }


//     }

//     Doc.data->data = (struct sentence * )malloc( sizeof(struct sentence* )); 

//     int len = strlen(text); 

//     for(int i = 0 ; i < len ; i ++){


//     }


    
// }

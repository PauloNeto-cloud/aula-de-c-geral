#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_VIDEO 100
#define MAX_GENERO_VIDEO 100
#define MAX_USUARIO 100
#define MAX_FAVORITOS 100

typedef struct {
    int id;
    char video[MAX_NOME_VIDEO];
    char genero[MAX_GENERO_VIDEO];
} Video;

typedef struct {
    int id;
    char nome[MAX_USUARIO];
    int videos_favoritos[MAX_FAVORITOS];
    int num_favoritos;
} Usuario;

void adicionar_video(FILE *video_file);
void adicionar_usuario(FILE *user_file);
void listar_videos(FILE *video_file);
void listar_usuarios(FILE *user_file);
void adicionar_favorito(FILE *video_file, FILE *user_file);
void listar_usuarios_com_favoritos(FILE *user_file, FILE *video_file);

int main() {
    FILE *video_file, *user_file;

    video_file = fopen("videos.bin", "rb+");
    if (!video_file) video_file = fopen("videos.bin", "wb+");

    user_file = fopen("usuarios.bin", "rb+");
    if (!user_file) user_file = fopen("usuarios.bin", "wb+");

    if (!video_file || !user_file) {
        printf("\n[ERRO] Não foi possível abrir os arquivos de dados!\n");
        return 1;
    }

    int opcao;
    do {
        printf("\n=== SISTEMA DE RECOMENDAÇÃO DE VÍDEOS ===\n");
        printf("\n1. Cadastrar novo vídeo");
        printf("\n2. Cadastrar novo usuário");
        printf("\n3. Visualizar catálogo de vídeos");
        printf("\n4. Listar todos os usuários");
        printf("\n5. Adicionar vídeo aos favoritos");
        printf("\n6. Consultar favoritos dos usuários");
        printf("\n7. Sair do sistema");
        printf("\n\nDigite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_video(video_file);
                break;
            case 2:
                adicionar_usuario(user_file);
                break;
            case 3:
                listar_videos(video_file);
                break;
            case 4:
                listar_usuarios(user_file);
                break;
            case 5:
                adicionar_favorito(video_file, user_file);
                break;
            case 6:
                listar_usuarios_com_favoritos(user_file, video_file);
                break;
            case 7:
                printf("\nObrigado por usar nosso sistema! Até logo!\n");
                break;
            default:
                printf("\n[ATENÇÃO] Opção inválida! Por favor, digite um número entre 1 e 7.\n");
        }
    } while (opcao != 7);

    fclose(video_file);
    fclose(user_file);

    return 0;
}

void adicionar_video(FILE *video_file) {
    Video video = {0};
    printf("\n--- CADASTRO DE NOVO VÍDEO ---\n");
    printf("Código do vídeo (ID): ");
    scanf("%d", &video.id);
    printf("Título do vídeo: ");
    getchar();
    fgets(video.video, MAX_NOME_VIDEO, stdin);
    strtok(video.video, "\n");
    printf("Gênero/Categoria: ");
    fgets(video.genero, MAX_GENERO_VIDEO, stdin);
    strtok(video.genero, "\n");

    fseek(video_file, 0, SEEK_END);
    fwrite(&video, sizeof(Video), 1, video_file);
    fflush(video_file);
    
    printf("\n[SUCESSO] Vídeo '%s' cadastrado com ID %d!\n", video.video, video.id);
}

void listar_videos(FILE *video_file) {
    Video video;
    rewind(video_file);
    
    printf("\n--- CATÁLOGO DE VÍDEOS DISPONÍVEIS ---\n");
    printf("\n%-5s | %-30s | %-20s\n", "ID", "TÍTULO", "GÊNERO");
    printf("-----+--------------------------------+-------------------\n");
    
    while (fread(&video, sizeof(Video), 1, video_file)) {
        printf("%-5d | %-30s | %-20s\n", video.id, video.video, video.genero);
    }
    
    printf("\nTotal de vídeos cadastrados: %ld\n", ftell(video_file)/sizeof(Video));
}

void adicionar_usuario(FILE *user_file) {
    Usuario usuario = {0};
    printf("\n--- CADASTRO DE NOVO USUÁRIO ---\n");
    printf("Código do usuário (ID): ");
    scanf("%d", &usuario.id);
    printf("Nome completo: ");
    getchar();
    fgets(usuario.nome, MAX_USUARIO, stdin);
    strtok(usuario.nome, "\n");
    usuario.num_favoritos = 0;

    fseek(user_file, 0, SEEK_END);
    fwrite(&usuario, sizeof(Usuario), 1, user_file);
    fflush(user_file);
    
    printf("\n[SUCESSO] Usuário '%s' cadastrado com ID %d!\n", usuario.nome, usuario.id);
}

void listar_usuarios(FILE *user_file) {
    Usuario usuario;
    rewind(user_file);
    
    printf("\n--- USUÁRIOS CADASTRADOS NO SISTEMA ---\n");
    printf("\n%-5s | %-30s | %-15s\n", "ID", "NOME", "FAVORITOS");
    printf("-----+--------------------------------+----------------\n");
    
    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        printf("%-5d | %-30s | %-15d\n", usuario.id, usuario.nome, usuario.num_favoritos);
    }
}

void adicionar_favorito(FILE *video_file, FILE *user_file) {
    Usuario usuario;
    Video video;
    int usuario_id, video_id;
    int encontrado = 0;

    printf("\n--- ADICIONAR VÍDEO AOS FAVORITOS ---\n");
    printf("Digite o ID do usuário: ");
    scanf("%d", &usuario_id);

    rewind(user_file);
    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        if (usuario.id == usuario_id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n[AVISO] Não existe usuário com o ID %d!\n", usuario_id);
        return;
    }

    printf("\nUsuário selecionado: %s\n", usuario.nome);
    listar_videos(video_file);

    printf("\nDigite o ID do vídeo que deseja favoritar: ");
    scanf("%d", &video_id);

    rewind(video_file);
    encontrado = 0;
    while (fread(&video, sizeof(Video), 1, video_file)) {
        if (video.id == video_id) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n[AVISO] O vídeo com ID %d não existe no catálogo!\n", video_id);
        return;
    }

    // Verifica se já está favoritado
    for (int i = 0; i < usuario.num_favoritos; i++) {
        if (usuario.videos_favoritos[i] == video_id) {
            printf("\n[AVISO] Este vídeo já está na lista de favoritos do usuário!\n");
            return;
        }
    }

    if (usuario.num_favoritos >= MAX_FAVORITOS) {
        printf("\n[AVISO] Limite de %d favoritos atingido para este usuário!\n", MAX_FAVORITOS);
        return;
    }

    usuario.videos_favoritos[usuario.num_favoritos++] = video_id;

    fseek(user_file, -sizeof(Usuario), SEEK_CUR);
    fwrite(&usuario, sizeof(Usuario), 1, user_file);
    fflush(user_file);

    printf("\n[SUCESSO] Vídeo '%s' adicionado aos favoritos de %s!\n", video.video, usuario.nome);
}

void listar_usuarios_com_favoritos(FILE *user_file, FILE *video_file) {
    Usuario usuario;
    Video video;

    rewind(user_file);
    printf("\n--- RELAÇÃO DE USUÁRIOS E SEUS FAVORITOS ---\n");

    while (fread(&usuario, sizeof(Usuario), 1, user_file)) {
        printf("\n» Usuário: %s (ID: %d)\n", usuario.nome, usuario.id);
        if (usuario.num_favoritos == 0) {
            printf("  └ Este usuário ainda não possui vídeos favoritos.\n");
            continue;
        }
        printf("  └ Vídeos favoritos (%d):\n", usuario.num_favoritos);
        for (int i = 0; i < usuario.num_favoritos; i++) {
            int id_fav = usuario.videos_favoritos[i];
            rewind(video_file);
            int encontrado = 0;
            while (fread(&video, sizeof(Video), 1, video_file)) {
                if (video.id == id_fav) {
                    printf("    %d. %s (%s)\n", i+1, video.video, video.genero);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("    %d. [Vídeo não encontrado - ID: %d]\n", i+1, id_fav);
            }
        }
    }
    printf("\n--- FIM DA LISTA ---\n");
}
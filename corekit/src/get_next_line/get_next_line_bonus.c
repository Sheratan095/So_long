/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 11:22:43 by maceccar          #+#    #+#             */
/*   Updated: 2024/05/03 00:47:17 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *reminder);
char	*format_result(char *reminder);
char	*format_new_reminder(char *reminder);

// Legge e aggiunge alla stringa main finchè non viene letto uno
//		'\n' oppure il file è finito
// Estrae la stringa risultante da quella main(reminder)
// Area il nuove reminder eliminando la linea appena eliminata, (substring?)
char	*get_next_line(int fd, t_bool last_call)
{
	static char	*reminder[OPEN_MAX];
	char		*output;

	if (last_call)
	{
		free(reminder[fd]);
		reminder[fd] = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	reminder[fd] = read_line(fd, reminder[fd]);
	if (!reminder[fd])
		return (NULL);
	output = format_result(reminder[fd]);
	reminder[fd] = format_new_reminder(reminder[fd]);
	return (output);
}

// Buffer viene usata solo come variabile d'appoggio durante la lettura
// Alloca per buffer_size +1(\n)
// 'read_bytes' inizializzato ad uno per 'assecondare' il ciclo successivo
// While la stringa 'main' non contiene uno '\n' &&
// 	il numero di byte letti è != 0 cioè quando si arriva alla fine del file
// Controllo che il numero di byte letti non sia < 0 => errore
// Null termina la stringa
// Aggiunge alla stringa grande il buffer letto
char	*read_line(int fd, char *reminder)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(reminder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(reminder);
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		reminder = ft_strjoin_free_s1_gnl(reminder, buffer);
		if (!reminder)
			return (free(buffer), NULL);
	}
	return (free(buffer), reminder);
}

// Se non esiste reminder nulla da restituire perchè la stringa è vuota
// Conta il numero dei caratteri del risultato e lo alloca +1(\n) +1(\0)
// Copia il reminder result fino allo '\n' o finchè non è finita
// Se trova uno \n lo aggiunge
// Infine aggiunge lo \0
char	*format_result(char *reminder)
{
	char	*result;
	int		i;

	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		result[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n')
	{
		result[i] = reminder[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// Arriva allo \n (fine della stringa di output) o alla fine della string
// Se non c'è più niente vuol dire che il reminder deve essere vuoto
// 'new_reminder' allocato per la lunghezza totale - lunghezza
// 		della stringa risultante +1(\0)
// i++ per oltrapassare lo '\n' nel vecchio reminder (fine dell'output)
// Liberato il vecchio reminder
char	*format_new_reminder(char *reminder)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen_gnl(reminder) - i + 1));
	if (!result)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i])
		result[j++] = reminder[i++];
	result[j] = '\0';
	free(reminder);
	return (result);
}

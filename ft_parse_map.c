/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 06:48:17 by vde-frei          #+#    #+#             */
/*   Updated: 2023/10/12 11:06:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coords	*ft_process(t_fdf *data, char *line);
static	int32_t	ft_count(char *line);
static	int32_t	ft_get_width(char *line);

t_coords	*ft_parse_map(t_fdf *data, char *map_path)
{
	int32_t		fd;
	char		*readstr;
	char		*line;

	readstr = NULL;
	data->map_height = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0 || !ft_strnstr(map_path, ".fdf", ft_strlen(map_path)))
		ft_error("Invalid file or extension!");
	while (true)
	{
		line = get_next_line(fd);
		if (line)
		{
			readstr = ft_str_append(readstr, line);
			data->map_height++;
		}
		else
			break ;
		free(line);
	}
	close(fd);
	return (ft_process(data, readstr));
}

static t_coords	*ft_process(t_fdf *data, char *line)
{
	int32_t		i;
	int32_t		size;
	t_coords	*coords;
	char		*linecpy;

	i = 0;
	linecpy = line;
	size = ft_count(linecpy);
	coords = ft_calloc(size + 1, sizeof(t_coords));
	while (i < size)
	{
		while (ft_isspace(*linecpy) && *linecpy)
			linecpy++;
		coords[i].height = ft_atoi(linecpy);
		while (!ft_isspace(*linecpy) && *linecpy)
			linecpy++;
		i++;
	}
	data->map_width = ft_get_width(line);
	free(line);
	return (coords);
}

static	int32_t	ft_count(char *line)
{
	int32_t	count;

	count = 0;
	while (*line)
	{
		while (ft_isspace(*line) && *line)
			line++;
		if (ft_isdigit(*line) || *line == '-')
			count++;
		while (!ft_isspace(*line) && *line)
			line++;
	}
	return (count);
}

static	int32_t	ft_get_width(char *line)
{
	int32_t	count;

	count = 0;
	while (*line && *line != '\n')
	{
		while (*line == ' ' && *line)
			line++;
		if (ft_isdigit(*line) || *line == '-')
			count++;
		while (*line != ' ' && *line)
		{
			if (*line == '\n')
				break ;
			line++;
		}
	}
	return (count);
}

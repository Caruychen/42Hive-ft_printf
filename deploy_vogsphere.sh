# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    deploy_vogsphere.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 08:28:35 by cchen             #+#    #+#              #
#    Updated: 2022/03/01 08:31:09 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VOGSPHERE=$(ls | sed -n '/intra-uuid/p')

rm -rf ./${VOGSPHERE}/*
cp ./$REPO_NAME/Makefile ./${VOGSPHERE}
cp ./$REPO_NAME/author ./${VOGSPHERE}
cp -r ./$REPO_NAME/srcs ./${VOGSPHERE}
cp -r ./$REPO_NAME/includes ./${VOGSPHERE}
cp -r ./$REPO_NAME/libft ./${VOGSPHERE}

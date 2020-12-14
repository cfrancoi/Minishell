#!/bin/bash


./Minishell < ./MshT > ./log2

bash < ./MshT > ./log1

diff log1 log2


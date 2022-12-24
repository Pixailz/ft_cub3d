#!/bin/bash

TARGET=${1}
LOG_FILE="deepthought"
TEST_DIR="test"

R="\e[31m"
G="\e[32m"
B="\e[34m"
RR="\e[0m"

VALID_MAP_00=$(cat << EOF
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

111111
1001011
1010001
1100N11
111111
EOF
)

function	test_log()
{
	local	mode=${1}
	local	msg=${2}

	if [ ${mode} == 1 ]; then
		printf "${msg}\n"
	elif [ ${mode} == 2 ]; then
		printf "${msg}\n" >> ${LOG_FILE}
	elif [ ${mode} == 3 ]; then
		printf "${msg}\n"
		printf "${msg}\n" >> ${LOG_FILE}
	fi
}

function	exec_parse
{
	local	args=${1}
	local	expected_return_value=${2}
	local	return_value

	${TARGET} ${args} 420>${TEST_DIR}/debug.log 2>/dev/null
	return_value=$(sed -n -E 's|return_value=\[(-?[0-9]*)\]|\1|p' ${TEST_DIR}/debug.log)
	if [ "${return_value}" != ${expected_return_value} ]; then
		test_log 3 "return_value not ${R}good${RR} ${path_to_config}"
		test_log 2 "   expected [${expected_return_value}] | your [${return_value}]"
	else
		test_log 2 "return_value ${G}good${RR} ${path_to_config}"
	fi
	test_log 2 "   args = [${args}]"
	test_log 2 "   return to stderr [$(cat ${TEST_DIR}/debug.log)]"
}

function	exec_parse_perm()
{
	local	args=${1}
	local	expected_return_value=${2}
	local	return_value

	${TARGET} ${args} 420>${TEST_DIR}/debug.log
	return_value=$(grep params_done ${TEST_DIR}/debug.log)
	if [ ${return_value} != "params_done" ]; then
		test_log 3 "return_value not ${R}good${RR} ${path_to_config}"
		test_log 2 "   expected [${expected_return_value}] | your [${return_value}]"
	else
		test_log 2 "return_value ${G}good${RR} ${path_to_config}"
	fi
	test_log 2 "   args = [${args}]"
	test_log 2 "   return to stderr [$(cat ${TEST_DIR}/debug.log)]"
}

function	init_parsing_args()
{
	TMP_DIR=${TEST_DIR}/permission
	mkdir ${TMP_DIR}

	printf "%s" "${VALID_MAP_00}" > ${TEST_DIR}/permission/map_chmod_377.cub
	chmod 377 ${TEST_DIR}/permission/map_chmod_377.cub
	printf "%s" "${VALID_MAP_00}" > ${TEST_DIR}/permission/map_chmod_400.cub
	chmod 400 ${TEST_DIR}/permission/map_chmod_400.cub
}

function	parsing_args()
{
	init_parsing_args
	exec_parse "." 1		# "." should not be
	exec_parse ".cub" 3		# ".cub" should not be good
	exec_parse "..cub" 3	# "..cub" should be good
	exec_parse "test.cub" 3	# "..cub" should be good
	exec_parse "test..cub" 3	# "..cub" should be good

	exec_parse "${TEST_DIR}/permission/map_chmod_377.cub" 3
	exec_parse "${TEST_DIR}/permission/map_chmod_400.cub" -1
}



function	parsing_map()
{
	exec_parse ""
}

function	init_entry()
{
	[ -f ${LOG_FILE} ] && rm -rf ${LOG_FILE}
	[ -d ${TEST_DIR} ] && rm -rf ${TEST_DIR}
	mkdir ${TEST_DIR}
}

function	main()
{
	init_entry
	parsing_args
	parsing_map
	rm -rf ${TEST_DIR}
}

if [ ! -f "${TARGET}" ]; then
	printf "first args must be cub3D executable\n"
	exit
fi

main

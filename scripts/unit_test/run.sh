#!/bin/bash

BASE_DIR=$(realpath ${BASH_SOURCE[0]})
BASE_DIR=${BASE_DIR%\/*}
TARGET=${1}
LOG_FILE="${BASE_DIR}/deepthought"
TEST_DIR="${BASE_DIR}/test"
EXEC_PATH="${TEST_DIR}/executable"
source ${BASE_DIR}/.map

R="\e[31m"
G="\e[32m"
B="\e[34m"
RR="\e[0m"


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

	${EXEC_PATH} ${args} 420>${TEST_DIR}/debug.log 2>/dev/null
	return_value=$(sed -n -E 's|return_value=\[(-?[0-9]*)\]|\1|p' ${TEST_DIR}/debug.log)
	if [ "${return_value}" != "${expected_return_value}" ]; then
		test_log 3 "return_value not ${R}good${RR} ${path_to_config}"
		test_log 3 "   args = [${args}]"
		test_log 2 "   expected [${expected_return_value}] | your [${return_value}]"
	else
		test_log 2 "return_value ${G}good${RR} ${path_to_config}"
		test_log 2 "   args = [${args}]"
	fi
	# test_log 2 "   debug log [$(cat ${TEST_DIR}/debug.log)]"
}

function	exec_parse_perm()
{
	local	args=${1}
	local	expected_return_value=${2}
	local	return_value

	${EXEC_PATH} ${args} 420>${TEST_DIR}/debug.log 2>/dev/null
	return_value=$(grep params_done ${TEST_DIR}/debug.log)
	if [ ${return_value} != "params_done" ]; then
		test_log 3 "return_value not ${R}good${RR} ${path_to_config}"
		test_log 3 "   args = [${args}]"
		test_log 2 "   expected [${expected_return_value}] | your [${return_value}]"
	else
		test_log 2 "return_value ${G}good${RR} ${path_to_config}"
		test_log 2 "   args = [${args}]"
	fi
	# test_log 2 "   debug log [$(cat ${TEST_DIR}/debug.log)]"
}

function	get_correct_texture()
{
	echo "test" > ${TEST_DIR}/path_to_the_north_texture
	echo "test" > ${TEST_DIR}/path_to_the_east_texture
	echo "test" > ${TEST_DIR}/path_to_the_west_texture
	echo "test" > ${TEST_DIR}/path_to_the_south_texture
}

function	get_incorrect_texture()
{
	rm -rf ${TEST_DIR}/path_to_the_north_texture
	rm -rf ${TEST_DIR}/path_to_the_east_texture
	rm -rf ${TEST_DIR}/path_to_the_west_texture
	rm -rf ${TEST_DIR}/path_to_the_south_texture
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

function	create_map()
{
	local	file_content="${1}"
	local	file_path="${TEST_DIR}/map/${2}.cub"

	printf "%s" "${file_content}" > ${file_path}
}

function	create_maps()
{
	mkdir "${TEST_DIR}/map"
	create_map "${VALID_MAP_00}" "valid_map_00"
	create_map "${VALID_MAP_01}" "valid_map_01"
	create_map "${VALID_MAP_02}" "valid_map_02"
	create_map "${VALID_MAP_03}" "valid_map_03"
	create_map "${VALID_MAP_04}" "valid_map_04"
	create_map "${INVALID_MAP_00}" "invalid_map_00"
	create_map "${INVALID_MAP_01}" "invalid_map_01"
	create_map "${INVALID_MAP_02}" "invalid_map_02"
	create_map "${INVALID_MAP_03}" "invalid_map_03"
	create_map "${INVALID_MAP_04}" "invalid_map_04"
	create_map "${INVALID_MAP_05}" "invalid_map_05"
	create_map "${INVALID_MAP_06}" "invalid_map_06"
	create_map "${INVALID_MAP_07}" "invalid_map_07"
	create_map "${INVALID_MAP_08}" "invalid_map_08"
	create_map "${INVALID_MAP_09}" "invalid_map_09"
	create_map "${INVALID_MAP_10}" "invalid_map_10"
}

function	parsing_map()
{
	get_incorrect_texture
	exec_parse "${TEST_DIR}/map/valid_map_00.cub" 511
	touch "${TEST_DIR}/path_to_the_north_texture"
	exec_parse "${TEST_DIR}/map/valid_map_00.cub" 767
	touch "${TEST_DIR}/path_to_the_south_texture"
	exec_parse "${TEST_DIR}/map/valid_map_00.cub" 1279
	touch "${TEST_DIR}/path_to_the_west_texture"
	exec_parse "${TEST_DIR}/map/valid_map_00.cub" 2303
	touch "${TEST_DIR}/path_to_the_east_texture"
	exec_parse "${TEST_DIR}/map/valid_map_00.cub" -1
	exec_parse "${TEST_DIR}/map/valid_map_01.cub" -1
	exec_parse "${TEST_DIR}/map/valid_map_02.cub" -1
	exec_parse "${TEST_DIR}/map/valid_map_03.cub" -1
	exec_parse "${TEST_DIR}/map/valid_map_04.cub" -1

	exec_parse "${TEST_DIR}/map/invalid_map_00.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_01.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_02.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_03.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_04.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_05.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_06.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_07.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_08.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_09.cub" -1
	exec_parse "${TEST_DIR}/map/invalid_map_10.cub" -1
}

function	init_entry()
{
	[ -f ${LOG_FILE} ] && rm -rf ${LOG_FILE}
	[ -d ${TEST_DIR} ] && rm -rf ${TEST_DIR}
	mkdir ${TEST_DIR}
	cp ${TARGET} ${EXEC_PATH}
	get_correct_texture
	create_maps
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

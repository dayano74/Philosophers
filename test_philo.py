#!/usr/bin/env python3
# filepath: /home/dayano/Desktop/13_github/Philosophers/test_philo.py

import subprocess
import time
import os
import signal
import sys
import re

# 設定
PHILO_PATH = "./philo"
TIMEOUT = 5  # 基本のタイムアウト（秒）
LONG_TIMEOUT = 10  # 長時間テスト用タイムアウト（秒）

# 色付きテキスト出力のためのANSIコード
class Colors:
	HEADER = '\033[95m'
	BLUE = '\033[94m'
	GREEN = '\033[92m'
	YELLOW = '\033[93m'
	RED = '\033[91m'
	ENDC = '\033[0m'
	BOLD = '\033[1m'

def print_header(text):
	print(f"{Colors.HEADER}{Colors.BOLD}{'=' * 60}{Colors.ENDC}")
	print(f"{Colors.HEADER}{Colors.BOLD}{text.center(60)}{Colors.ENDC}")
	print(f"{Colors.HEADER}{Colors.BOLD}{'=' * 60}{Colors.ENDC}")

def print_test(test_name):
	print(f"\n{Colors.BLUE}{Colors.BOLD}[TEST] {test_name}{Colors.ENDC}")

def print_pass():
	print(f"{Colors.GREEN}{Colors.BOLD}[PASS]{Colors.ENDC}")

def print_fail():
	print(f"{Colors.RED}{Colors.BOLD}[FAIL]{Colors.ENDC}")

def print_warning(text):
	print(f"{Colors.YELLOW}{Colors.BOLD}[WARNING] {text}{Colors.ENDC}")

def print_info(text):
	print(f"{Colors.BLUE}[INFO] {text}{Colors.ENDC}")

def print_output(output):
	print(f"\n--- Command Output ---\n{output}\n----------------------")

# テスト実行関数
def run_test(args, expected_status=0, timeout=TIMEOUT, check_output=None):
	cmd = [PHILO_PATH] + [str(arg) for arg in args]
	cmd_str = " ".join(cmd)

	print_info(f"Running command: {cmd_str}")

	try:
		process = subprocess.Popen(
			cmd,
			stdout=subprocess.PIPE,
			stderr=subprocess.PIPE,
			text=True,
			preexec_fn=os.setsid
		)

		try:
			stdout, stderr = process.communicate(timeout=timeout)
			output = stdout + stderr
			status = process.returncode

			if check_output:
				result = check_output(output)
				if not result:
					print_output(output[:500] + ("..." if len(output) > 500 else ""))
					print_fail()
					return False

			if status == expected_status:
				print_pass()
				return True
			else:
				print_output(output[:500] + ("..." if len(output) > 500 else ""))
				print_fail()
				print_info(f"Expected status {expected_status}, got {status}")
				return False

		except subprocess.TimeoutExpired:
			os.killpg(os.getpgid(process.pid), signal.SIGTERM)
			print_warning("Test timed out")
			print_fail()
			return False

	except Exception as e:
		print_fail()
		print_info(f"Error running test: {e}")
		return False

# 特定の出力をチェックする関数
def has_death_message(output):
	return "died" in output

def count_meals(output):
	# 食事回数をカウント
	eating_count = len(re.findall(r"is eating", output))
	return eating_count

def check_all_ate_enough(output, philo_count, meals_required):
	# 各哲学者が必要回数食事したか確認
	philosopher_meals = {}
	for i in range(1, philo_count + 1):
		pattern = rf"\d+ {i} is eating"
		philosopher_meals[i] = len(re.findall(pattern, output))

	print_info(f"Meal counts: {philosopher_meals}")
	return all(count >= meals_required for count in philosopher_meals.values())

# テストケースの定義
def run_tests():
	passed = 0
	failed = 0

	# ビルドチェック
	if not os.path.exists(PHILO_PATH):
		print_warning(f"{PHILO_PATH} not found. Please compile the program first.")
		return

	print_header("基本テストケース")

	# テスト1: 正常動作
	def run_test(args, expected_status=0, timeout=TIMEOUT, check_output=None, timeout_is_success=False):
		cmd = [PHILO_PATH] + [str(arg) for arg in args]
		cmd_str = " ".join(cmd)

		print_info(f"Running command: {cmd_str}")

		try:
			process = subprocess.Popen(
				cmd,
				stdout=subprocess.PIPE,
				stderr=subprocess.PIPE,
				text=True,
				preexec_fn=os.setsid
			)

			try:
				stdout, stderr = process.communicate(timeout=timeout)
				output = stdout + stderr
				status = process.returncode

				if check_output:
					result = check_output(output)
					if not result:
						print_output(output[:500] + ("..." if len(output) > 500 else ""))
						print_fail()
						return False

				if status == expected_status:
					print_pass()
					return True
				else:
					print_output(output[:500] + ("..." if len(output) > 500 else ""))
					print_fail()
					print_info(f"Expected status {expected_status}, got {status}")
					return False

			except subprocess.TimeoutExpired:
				os.killpg(os.getpgid(process.pid), signal.SIGTERM)
				if timeout_is_success:
					print_info("Timeout occurred as expected")
					print_pass()
					return True
				else:
					print_warning("Test timed out")
					print_fail()
					return False

		except Exception as e:
			print_fail()
			print_info(f"Error running test: {e}")
			return False


# テスト1: 正常動作（タイムアウトを成功とする）
	print_test("正常動作 (5 800 200 200) - タイムアウト=成功")
	if run_test([5, 800, 200, 200], timeout=3, timeout_is_success=True):
		passed += 1
	else:
		failed += 1

	# テスト2: 食事回数指定
	print_test("食事回数指定 (5 800 200 200 7)")
	if run_test([5, 800, 200, 200, 7], timeout=LONG_TIMEOUT):
		passed += 1
	else:
		failed += 1

	print_header("エラーケース")

	# テスト3: 引数不足
	print_test("引数不足 (5 800 200)")
	if run_test([5, 800, 200], expected_status=1):
		passed += 1
	else:
		failed += 1

	# テスト4: 引数過剰
	print_test("引数過剰 (5 800 200 200 7 100)")
	if run_test([5, 800, 200, 200, 7, 100], expected_status=1):
		passed += 1
	else:
		failed += 1

	# テスト5: 無効な引数 (負の値)
	print_test("無効な引数 - 負の値 (5 -800 200 200)")
	if run_test([5, -800, 200, 200], expected_status=1):
		passed += 1
	else:
		failed += 1

	# テスト6: 数値でない引数
	print_test("数値でない引数 (5 800a 200 200)")
	if run_test(["5", "800a", "200", "200"], expected_status=1):
		passed += 1
	else:
		failed += 1

	# テスト7: ゼロ値の引数
	print_test("ゼロ値の引数 (0 800 200 200)")
	if run_test([0, 800, 200, 200], expected_status=1):
		passed += 1
	else:
		failed += 1

	print_header("極端なケース")

	# テスト8: 哲学者1人の場合
	print_test("哲学者1人 (1 800 200 200)")
	if run_test([1, 800, 200, 200], timeout=3, check_output=has_death_message):
		passed += 1
	else:
		failed += 1

	# テスト9: 死亡時間が短い場合
	print_test("死亡時間が短い (5 60 100 100)")
	if run_test([5, 60, 100, 100], timeout=3, check_output=has_death_message):
		passed += 1
	else:
		failed += 1

	# テスト10: 死亡しないことの確認
	print_test("死亡しないケース (5 800 200 200 2)")
	def no_death_message(output):
		if "died" in output:
			print_info("Unexpected death detected")
			return False
		return True

	if run_test([5, 800, 200, 200, 2], timeout=5, check_output=no_death_message):
		passed += 1
	else:
		failed += 1

	# テスト11: 全員が必要回数食事するか
	print_test("全員が必要回数食事 (3 800 200 200 3)")
	def check_meals(output):
		result = check_all_ate_enough(output, 3, 3)
		if not result:
			print_info("Not all philosophers ate enough times")
		return result

	if run_test([3, 800, 200, 200, 3], timeout=LONG_TIMEOUT, check_output=check_meals):
		passed += 1
	else:
		failed += 1

	# 結果表示
	print_header("テスト結果")
	print(f"合計: {passed + failed} テスト")
	print(f"{Colors.GREEN}成功: {passed}{Colors.ENDC}")
	print(f"{Colors.RED}失敗: {failed}{Colors.ENDC}")

	return passed, failed

if __name__ == "__main__":
	run_tests()

install:
	sudo apt -y update
	sudo apt -y install --no-install-recommends python3-dev
	pip install -r requirements.txt

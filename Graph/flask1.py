from flask import flask

app = flask(__name__)

@app.route("/")

def home():
	return "Hello! Main page<h1>Hello</h1>"


if __name__ == "__main__":
	app.run()
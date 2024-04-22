from ArduinoTemp.py import app  # Import the Flask application instance
from flask_sqlalchemy import SQLAlchemy

# Set the SQLAlchemy database URI
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///site.db'

# Create an instance of SQLAlchemy and bind it to the app
db = SQLAlchemy(app)

if __name__ == "__main__":
    # Run any database-related tests or operations here
    pass

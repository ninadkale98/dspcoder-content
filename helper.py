import os

def create_md_files(folder_location, text_file):
    # Ensure the folder exists, create if it doesn't
    os.makedirs(folder_location, exist_ok=True)

    # Read the content of the text file line by line
    with open(text_file, 'r') as file:
        lines = file.readlines()

    # Create a .md file for each line (question) in the text file
    for line in lines:
        # Clean up the line and strip leading/trailing whitespace
        question = line.strip()

        # If the line isn't empty, create a corresponding .md file
        if question:
            # Generate a valid file name by replacing spaces with underscores
            file_name = question.replace(' ', '_') + '.md'
            
            # Create the full path for the .md file in the specified folder
            md_file_path = os.path.join(folder_location, file_name)

            # Write the question as the content in the corresponding .md file
            with open(md_file_path, 'w') as md_file:
                md_file.write(f"# {question}\n")

            print(f"Markdown file created: {md_file_path}")

# Example usage
folder_location = '/Users/ninadkale/dspcoder/content/dspcoder-content/Questions/Array'
text_file = '/Users/ninadkale/dspcoder/content/helper.txt'
create_md_files(folder_location, text_file)

import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:

    d = person[person['email'].duplicated()]
    
    d = d.drop_duplicates(subset=['email'])

    d = d.rename(columns={'email': 'Email'})

    d.drop(columns='id', inplace=True)

    return d
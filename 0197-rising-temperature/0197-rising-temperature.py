import pandas as pd

def rising_temperature(weather: pd.DataFrame) -> pd.DataFrame:

    ids = []

    weather.sort_values(by='recordDate', inplace = True)
    weather.reset_index(drop = True,inplace = True)

    for i in range(1, len(weather)):

        if (weather.loc[i, 'temperature'] > weather.loc[i-1, 'temperature'] ) and (weather.loc[i, 'recordDate'] - weather.loc[i-1, 'recordDate'] == pd.Timedelta(days=1)):

            ids.append(weather.loc[i, 'id'])

    d = pd.DataFrame({'id': ids})

    return d
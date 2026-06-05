import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    
    employee = employee.drop(
        employee[employee['salary'] == employee['salary'].max()].index
    )

    if len(employee) == 0:
        return pd.DataFrame({'SecondHighestSalary': [None]})

    return pd.DataFrame({
        'SecondHighestSalary': [employee['salary'].max()]
    })
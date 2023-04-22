import gc
import glob
import geopandas as gpd

def shp_to_csv(shp_file_path,coordinate_sys,csv_filepath):
    """
    shp확장자 파일을 csv확장자 파일로 변환해주는 함수
    :param shp_file_path: 변환할 shp파일의 경로
    :param coordinate_sys: shp파일의 좌표계 정보 (ex. epsg:5174 , epsg:2097)
    :param csv_filepath: 변환한 csv파일을 저장할 경로
    :return: csv파일
    """
    # geoDataFrame 생성
    gdf = gpd.read_file(shp_file_path, encoding='CP949') # 또는 encoding='utf-8'
    # 좌표계 정보 설정
    gdf = gdf.to_crs(coordinate_sys)
    # csv파일로 변환
    gdf.to_csv(csv_filepath,encoding='utf-8',index=False)
    # 메모리 정리
    del gdf
    gc.collect()

if __name__ == "__main__":
    shp_to_csv("D:\\SKH\\DevStudy\\JupyterNotebook\\BigDataPromotion_Gwangjingu\\data\\area_of_use\\seoul_aou\\seoul_aou_org.shp",
               "epsg:5174","D:\\SKH\\DevStudy\\JupyterNotebook\\BigDataPromotion_Gwangjingu\\data\\area_of_use\\seoul_aou\\seoul_aou_org.csv")
    pass
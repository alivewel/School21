package add_response

import (
	"transmitter/pkg/models"
	pb "transmitter/transmitter"
	"gorm.io/gorm"
)

func AddResponse(response *pb.Response, DB *gorm.DB) error {
	var addResponse models.Response
	addResponse.Session_id = response.SessionId
	addResponse.Frequency = response.Frequency
	timeObj := response.Timestamp.AsTime()
	addResponse.Timestamp = timeObj.Format("2006-01-02 15:04:05")
	
	// Append to the response table
	if result := DB.Create(&addResponse); result.Error != nil {
		return result.Error
	}
	return nil
}

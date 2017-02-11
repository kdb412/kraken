##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=kraken
ConfigurationName      :=Debug
WorkspacePath          :=/Users/skullybox/Desktop/kraken/src
ProjectPath            :=/Users/skullybox/Desktop/kraken/src
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Irfan Gulamali
Date                   :=10/02/2017
CodeLitePath           :="/Users/skullybox/Library/Application Support/codelite"
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)TESTDB 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="kraken.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/b64.c$(ObjectSuffix) $(IntermediateDirectory)/camellia.c$(ObjectSuffix) $(IntermediateDirectory)/colgetSize.c$(ObjectSuffix) $(IntermediateDirectory)/colgetType.c$(ObjectSuffix) $(IntermediateDirectory)/k_login.c$(ObjectSuffix) $(IntermediateDirectory)/k_logout.c$(ObjectSuffix) $(IntermediateDirectory)/k_mount.c$(ObjectSuffix) $(IntermediateDirectory)/k_query.c$(ObjectSuffix) $(IntermediateDirectory)/k_stop.c$(ObjectSuffix) $(IntermediateDirectory)/k_umount.c$(ObjectSuffix) \
	$(IntermediateDirectory)/kraken.c$(ObjectSuffix) $(IntermediateDirectory)/krk__checkdbpath.c$(ObjectSuffix) $(IntermediateDirectory)/krk__create_user.c$(ObjectSuffix) $(IntermediateDirectory)/krk__createdb.c$(ObjectSuffix) $(IntermediateDirectory)/krk__createtb.c$(ObjectSuffix) $(IntermediateDirectory)/krk__mountdb.c$(ObjectSuffix) $(IntermediateDirectory)/krk__umountdb.c$(ObjectSuffix) $(IntermediateDirectory)/krk_b64dec.c$(ObjectSuffix) $(IntermediateDirectory)/krk_b64enc.c$(ObjectSuffix) $(IntermediateDirectory)/krk_checkstoragepath.c$(ObjectSuffix) \
	$(IntermediateDirectory)/krk_create_user.c$(ObjectSuffix) $(IntermediateDirectory)/krk_createdb.c$(ObjectSuffix) $(IntermediateDirectory)/krk_createtb.c$(ObjectSuffix) $(IntermediateDirectory)/krk_get_columns_sql.c$(ObjectSuffix) $(IntermediateDirectory)/krk_get_sql_mode.c$(ObjectSuffix) $(IntermediateDirectory)/krk_get_sql_token.c$(ObjectSuffix) $(IntermediateDirectory)/krk_get_table_sql.c$(ObjectSuffix) $(IntermediateDirectory)/krk_login.c$(ObjectSuffix) $(IntermediateDirectory)/krk_logout.c$(ObjectSuffix) $(IntermediateDirectory)/krk_mountdb.c$(ObjectSuffix) \
	$(IntermediateDirectory)/krk_query_process.c$(ObjectSuffix) $(IntermediateDirectory)/krk_queryrequest_thread.c$(ObjectSuffix) $(IntermediateDirectory)/krk_queryservice.c$(ObjectSuffix) $(IntermediateDirectory)/krk_sql_spc_strip.c$(ObjectSuffix) $(IntermediateDirectory)/krk_startqueryservice.c$(ObjectSuffix) $(IntermediateDirectory)/krk_storage.c$(ObjectSuffix) $(IntermediateDirectory)/krk_umountdb.c$(ObjectSuffix) $(IntermediateDirectory)/q_processor.c$(ObjectSuffix) $(IntermediateDirectory)/query_context.c$(ObjectSuffix) $(IntermediateDirectory)/randbyte.c$(ObjectSuffix) \
	$(IntermediateDirectory)/randint.c$(ObjectSuffix) $(IntermediateDirectory)/sha1.c$(ObjectSuffix) $(IntermediateDirectory)/storage_path.c$(ObjectSuffix) $(IntermediateDirectory)/test.c$(ObjectSuffix) $(IntermediateDirectory)/testdb.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/b64.c$(ObjectSuffix): b64.c $(IntermediateDirectory)/b64.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/b64.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/b64.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/b64.c$(DependSuffix): b64.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/b64.c$(ObjectSuffix) -MF$(IntermediateDirectory)/b64.c$(DependSuffix) -MM b64.c

$(IntermediateDirectory)/b64.c$(PreprocessSuffix): b64.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/b64.c$(PreprocessSuffix) b64.c

$(IntermediateDirectory)/camellia.c$(ObjectSuffix): camellia.c $(IntermediateDirectory)/camellia.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/camellia.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/camellia.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/camellia.c$(DependSuffix): camellia.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/camellia.c$(ObjectSuffix) -MF$(IntermediateDirectory)/camellia.c$(DependSuffix) -MM camellia.c

$(IntermediateDirectory)/camellia.c$(PreprocessSuffix): camellia.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/camellia.c$(PreprocessSuffix) camellia.c

$(IntermediateDirectory)/colgetSize.c$(ObjectSuffix): colgetSize.c $(IntermediateDirectory)/colgetSize.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/colgetSize.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/colgetSize.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/colgetSize.c$(DependSuffix): colgetSize.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/colgetSize.c$(ObjectSuffix) -MF$(IntermediateDirectory)/colgetSize.c$(DependSuffix) -MM colgetSize.c

$(IntermediateDirectory)/colgetSize.c$(PreprocessSuffix): colgetSize.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/colgetSize.c$(PreprocessSuffix) colgetSize.c

$(IntermediateDirectory)/colgetType.c$(ObjectSuffix): colgetType.c $(IntermediateDirectory)/colgetType.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/colgetType.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/colgetType.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/colgetType.c$(DependSuffix): colgetType.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/colgetType.c$(ObjectSuffix) -MF$(IntermediateDirectory)/colgetType.c$(DependSuffix) -MM colgetType.c

$(IntermediateDirectory)/colgetType.c$(PreprocessSuffix): colgetType.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/colgetType.c$(PreprocessSuffix) colgetType.c

$(IntermediateDirectory)/k_login.c$(ObjectSuffix): k_login.c $(IntermediateDirectory)/k_login.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_login.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_login.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_login.c$(DependSuffix): k_login.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_login.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_login.c$(DependSuffix) -MM k_login.c

$(IntermediateDirectory)/k_login.c$(PreprocessSuffix): k_login.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_login.c$(PreprocessSuffix) k_login.c

$(IntermediateDirectory)/k_logout.c$(ObjectSuffix): k_logout.c $(IntermediateDirectory)/k_logout.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_logout.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_logout.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_logout.c$(DependSuffix): k_logout.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_logout.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_logout.c$(DependSuffix) -MM k_logout.c

$(IntermediateDirectory)/k_logout.c$(PreprocessSuffix): k_logout.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_logout.c$(PreprocessSuffix) k_logout.c

$(IntermediateDirectory)/k_mount.c$(ObjectSuffix): k_mount.c $(IntermediateDirectory)/k_mount.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_mount.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_mount.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_mount.c$(DependSuffix): k_mount.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_mount.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_mount.c$(DependSuffix) -MM k_mount.c

$(IntermediateDirectory)/k_mount.c$(PreprocessSuffix): k_mount.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_mount.c$(PreprocessSuffix) k_mount.c

$(IntermediateDirectory)/k_query.c$(ObjectSuffix): k_query.c $(IntermediateDirectory)/k_query.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_query.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_query.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_query.c$(DependSuffix): k_query.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_query.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_query.c$(DependSuffix) -MM k_query.c

$(IntermediateDirectory)/k_query.c$(PreprocessSuffix): k_query.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_query.c$(PreprocessSuffix) k_query.c

$(IntermediateDirectory)/k_stop.c$(ObjectSuffix): k_stop.c $(IntermediateDirectory)/k_stop.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_stop.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_stop.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_stop.c$(DependSuffix): k_stop.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_stop.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_stop.c$(DependSuffix) -MM k_stop.c

$(IntermediateDirectory)/k_stop.c$(PreprocessSuffix): k_stop.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_stop.c$(PreprocessSuffix) k_stop.c

$(IntermediateDirectory)/k_umount.c$(ObjectSuffix): k_umount.c $(IntermediateDirectory)/k_umount.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/k_umount.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/k_umount.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/k_umount.c$(DependSuffix): k_umount.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/k_umount.c$(ObjectSuffix) -MF$(IntermediateDirectory)/k_umount.c$(DependSuffix) -MM k_umount.c

$(IntermediateDirectory)/k_umount.c$(PreprocessSuffix): k_umount.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/k_umount.c$(PreprocessSuffix) k_umount.c

$(IntermediateDirectory)/kraken.c$(ObjectSuffix): kraken.c $(IntermediateDirectory)/kraken.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/kraken.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/kraken.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/kraken.c$(DependSuffix): kraken.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/kraken.c$(ObjectSuffix) -MF$(IntermediateDirectory)/kraken.c$(DependSuffix) -MM kraken.c

$(IntermediateDirectory)/kraken.c$(PreprocessSuffix): kraken.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/kraken.c$(PreprocessSuffix) kraken.c

$(IntermediateDirectory)/krk__checkdbpath.c$(ObjectSuffix): krk__checkdbpath.c $(IntermediateDirectory)/krk__checkdbpath.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__checkdbpath.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__checkdbpath.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__checkdbpath.c$(DependSuffix): krk__checkdbpath.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__checkdbpath.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__checkdbpath.c$(DependSuffix) -MM krk__checkdbpath.c

$(IntermediateDirectory)/krk__checkdbpath.c$(PreprocessSuffix): krk__checkdbpath.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__checkdbpath.c$(PreprocessSuffix) krk__checkdbpath.c

$(IntermediateDirectory)/krk__create_user.c$(ObjectSuffix): krk__create_user.c $(IntermediateDirectory)/krk__create_user.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__create_user.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__create_user.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__create_user.c$(DependSuffix): krk__create_user.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__create_user.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__create_user.c$(DependSuffix) -MM krk__create_user.c

$(IntermediateDirectory)/krk__create_user.c$(PreprocessSuffix): krk__create_user.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__create_user.c$(PreprocessSuffix) krk__create_user.c

$(IntermediateDirectory)/krk__createdb.c$(ObjectSuffix): krk__createdb.c $(IntermediateDirectory)/krk__createdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__createdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__createdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__createdb.c$(DependSuffix): krk__createdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__createdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__createdb.c$(DependSuffix) -MM krk__createdb.c

$(IntermediateDirectory)/krk__createdb.c$(PreprocessSuffix): krk__createdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__createdb.c$(PreprocessSuffix) krk__createdb.c

$(IntermediateDirectory)/krk__createtb.c$(ObjectSuffix): krk__createtb.c $(IntermediateDirectory)/krk__createtb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__createtb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__createtb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__createtb.c$(DependSuffix): krk__createtb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__createtb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__createtb.c$(DependSuffix) -MM krk__createtb.c

$(IntermediateDirectory)/krk__createtb.c$(PreprocessSuffix): krk__createtb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__createtb.c$(PreprocessSuffix) krk__createtb.c

$(IntermediateDirectory)/krk__mountdb.c$(ObjectSuffix): krk__mountdb.c $(IntermediateDirectory)/krk__mountdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__mountdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__mountdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__mountdb.c$(DependSuffix): krk__mountdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__mountdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__mountdb.c$(DependSuffix) -MM krk__mountdb.c

$(IntermediateDirectory)/krk__mountdb.c$(PreprocessSuffix): krk__mountdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__mountdb.c$(PreprocessSuffix) krk__mountdb.c

$(IntermediateDirectory)/krk__umountdb.c$(ObjectSuffix): krk__umountdb.c $(IntermediateDirectory)/krk__umountdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk__umountdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk__umountdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk__umountdb.c$(DependSuffix): krk__umountdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk__umountdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk__umountdb.c$(DependSuffix) -MM krk__umountdb.c

$(IntermediateDirectory)/krk__umountdb.c$(PreprocessSuffix): krk__umountdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk__umountdb.c$(PreprocessSuffix) krk__umountdb.c

$(IntermediateDirectory)/krk_b64dec.c$(ObjectSuffix): krk_b64dec.c $(IntermediateDirectory)/krk_b64dec.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_b64dec.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_b64dec.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_b64dec.c$(DependSuffix): krk_b64dec.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_b64dec.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_b64dec.c$(DependSuffix) -MM krk_b64dec.c

$(IntermediateDirectory)/krk_b64dec.c$(PreprocessSuffix): krk_b64dec.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_b64dec.c$(PreprocessSuffix) krk_b64dec.c

$(IntermediateDirectory)/krk_b64enc.c$(ObjectSuffix): krk_b64enc.c $(IntermediateDirectory)/krk_b64enc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_b64enc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_b64enc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_b64enc.c$(DependSuffix): krk_b64enc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_b64enc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_b64enc.c$(DependSuffix) -MM krk_b64enc.c

$(IntermediateDirectory)/krk_b64enc.c$(PreprocessSuffix): krk_b64enc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_b64enc.c$(PreprocessSuffix) krk_b64enc.c

$(IntermediateDirectory)/krk_checkstoragepath.c$(ObjectSuffix): krk_checkstoragepath.c $(IntermediateDirectory)/krk_checkstoragepath.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_checkstoragepath.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_checkstoragepath.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_checkstoragepath.c$(DependSuffix): krk_checkstoragepath.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_checkstoragepath.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_checkstoragepath.c$(DependSuffix) -MM krk_checkstoragepath.c

$(IntermediateDirectory)/krk_checkstoragepath.c$(PreprocessSuffix): krk_checkstoragepath.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_checkstoragepath.c$(PreprocessSuffix) krk_checkstoragepath.c

$(IntermediateDirectory)/krk_create_user.c$(ObjectSuffix): krk_create_user.c $(IntermediateDirectory)/krk_create_user.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_create_user.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_create_user.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_create_user.c$(DependSuffix): krk_create_user.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_create_user.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_create_user.c$(DependSuffix) -MM krk_create_user.c

$(IntermediateDirectory)/krk_create_user.c$(PreprocessSuffix): krk_create_user.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_create_user.c$(PreprocessSuffix) krk_create_user.c

$(IntermediateDirectory)/krk_createdb.c$(ObjectSuffix): krk_createdb.c $(IntermediateDirectory)/krk_createdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_createdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_createdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_createdb.c$(DependSuffix): krk_createdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_createdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_createdb.c$(DependSuffix) -MM krk_createdb.c

$(IntermediateDirectory)/krk_createdb.c$(PreprocessSuffix): krk_createdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_createdb.c$(PreprocessSuffix) krk_createdb.c

$(IntermediateDirectory)/krk_createtb.c$(ObjectSuffix): krk_createtb.c $(IntermediateDirectory)/krk_createtb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_createtb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_createtb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_createtb.c$(DependSuffix): krk_createtb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_createtb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_createtb.c$(DependSuffix) -MM krk_createtb.c

$(IntermediateDirectory)/krk_createtb.c$(PreprocessSuffix): krk_createtb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_createtb.c$(PreprocessSuffix) krk_createtb.c

$(IntermediateDirectory)/krk_get_columns_sql.c$(ObjectSuffix): krk_get_columns_sql.c $(IntermediateDirectory)/krk_get_columns_sql.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_get_columns_sql.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_get_columns_sql.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_get_columns_sql.c$(DependSuffix): krk_get_columns_sql.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_get_columns_sql.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_get_columns_sql.c$(DependSuffix) -MM krk_get_columns_sql.c

$(IntermediateDirectory)/krk_get_columns_sql.c$(PreprocessSuffix): krk_get_columns_sql.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_get_columns_sql.c$(PreprocessSuffix) krk_get_columns_sql.c

$(IntermediateDirectory)/krk_get_sql_mode.c$(ObjectSuffix): krk_get_sql_mode.c $(IntermediateDirectory)/krk_get_sql_mode.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_get_sql_mode.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_get_sql_mode.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_get_sql_mode.c$(DependSuffix): krk_get_sql_mode.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_get_sql_mode.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_get_sql_mode.c$(DependSuffix) -MM krk_get_sql_mode.c

$(IntermediateDirectory)/krk_get_sql_mode.c$(PreprocessSuffix): krk_get_sql_mode.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_get_sql_mode.c$(PreprocessSuffix) krk_get_sql_mode.c

$(IntermediateDirectory)/krk_get_sql_token.c$(ObjectSuffix): krk_get_sql_token.c $(IntermediateDirectory)/krk_get_sql_token.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_get_sql_token.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_get_sql_token.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_get_sql_token.c$(DependSuffix): krk_get_sql_token.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_get_sql_token.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_get_sql_token.c$(DependSuffix) -MM krk_get_sql_token.c

$(IntermediateDirectory)/krk_get_sql_token.c$(PreprocessSuffix): krk_get_sql_token.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_get_sql_token.c$(PreprocessSuffix) krk_get_sql_token.c

$(IntermediateDirectory)/krk_get_table_sql.c$(ObjectSuffix): krk_get_table_sql.c $(IntermediateDirectory)/krk_get_table_sql.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_get_table_sql.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_get_table_sql.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_get_table_sql.c$(DependSuffix): krk_get_table_sql.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_get_table_sql.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_get_table_sql.c$(DependSuffix) -MM krk_get_table_sql.c

$(IntermediateDirectory)/krk_get_table_sql.c$(PreprocessSuffix): krk_get_table_sql.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_get_table_sql.c$(PreprocessSuffix) krk_get_table_sql.c

$(IntermediateDirectory)/krk_login.c$(ObjectSuffix): krk_login.c $(IntermediateDirectory)/krk_login.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_login.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_login.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_login.c$(DependSuffix): krk_login.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_login.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_login.c$(DependSuffix) -MM krk_login.c

$(IntermediateDirectory)/krk_login.c$(PreprocessSuffix): krk_login.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_login.c$(PreprocessSuffix) krk_login.c

$(IntermediateDirectory)/krk_logout.c$(ObjectSuffix): krk_logout.c $(IntermediateDirectory)/krk_logout.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_logout.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_logout.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_logout.c$(DependSuffix): krk_logout.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_logout.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_logout.c$(DependSuffix) -MM krk_logout.c

$(IntermediateDirectory)/krk_logout.c$(PreprocessSuffix): krk_logout.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_logout.c$(PreprocessSuffix) krk_logout.c

$(IntermediateDirectory)/krk_mountdb.c$(ObjectSuffix): krk_mountdb.c $(IntermediateDirectory)/krk_mountdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_mountdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_mountdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_mountdb.c$(DependSuffix): krk_mountdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_mountdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_mountdb.c$(DependSuffix) -MM krk_mountdb.c

$(IntermediateDirectory)/krk_mountdb.c$(PreprocessSuffix): krk_mountdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_mountdb.c$(PreprocessSuffix) krk_mountdb.c

$(IntermediateDirectory)/krk_query_process.c$(ObjectSuffix): krk_query_process.c $(IntermediateDirectory)/krk_query_process.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_query_process.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_query_process.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_query_process.c$(DependSuffix): krk_query_process.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_query_process.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_query_process.c$(DependSuffix) -MM krk_query_process.c

$(IntermediateDirectory)/krk_query_process.c$(PreprocessSuffix): krk_query_process.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_query_process.c$(PreprocessSuffix) krk_query_process.c

$(IntermediateDirectory)/krk_queryrequest_thread.c$(ObjectSuffix): krk_queryrequest_thread.c $(IntermediateDirectory)/krk_queryrequest_thread.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_queryrequest_thread.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_queryrequest_thread.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_queryrequest_thread.c$(DependSuffix): krk_queryrequest_thread.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_queryrequest_thread.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_queryrequest_thread.c$(DependSuffix) -MM krk_queryrequest_thread.c

$(IntermediateDirectory)/krk_queryrequest_thread.c$(PreprocessSuffix): krk_queryrequest_thread.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_queryrequest_thread.c$(PreprocessSuffix) krk_queryrequest_thread.c

$(IntermediateDirectory)/krk_queryservice.c$(ObjectSuffix): krk_queryservice.c $(IntermediateDirectory)/krk_queryservice.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_queryservice.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_queryservice.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_queryservice.c$(DependSuffix): krk_queryservice.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_queryservice.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_queryservice.c$(DependSuffix) -MM krk_queryservice.c

$(IntermediateDirectory)/krk_queryservice.c$(PreprocessSuffix): krk_queryservice.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_queryservice.c$(PreprocessSuffix) krk_queryservice.c

$(IntermediateDirectory)/krk_sql_spc_strip.c$(ObjectSuffix): krk_sql_spc_strip.c $(IntermediateDirectory)/krk_sql_spc_strip.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_sql_spc_strip.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_sql_spc_strip.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_sql_spc_strip.c$(DependSuffix): krk_sql_spc_strip.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_sql_spc_strip.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_sql_spc_strip.c$(DependSuffix) -MM krk_sql_spc_strip.c

$(IntermediateDirectory)/krk_sql_spc_strip.c$(PreprocessSuffix): krk_sql_spc_strip.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_sql_spc_strip.c$(PreprocessSuffix) krk_sql_spc_strip.c

$(IntermediateDirectory)/krk_startqueryservice.c$(ObjectSuffix): krk_startqueryservice.c $(IntermediateDirectory)/krk_startqueryservice.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_startqueryservice.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_startqueryservice.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_startqueryservice.c$(DependSuffix): krk_startqueryservice.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_startqueryservice.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_startqueryservice.c$(DependSuffix) -MM krk_startqueryservice.c

$(IntermediateDirectory)/krk_startqueryservice.c$(PreprocessSuffix): krk_startqueryservice.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_startqueryservice.c$(PreprocessSuffix) krk_startqueryservice.c

$(IntermediateDirectory)/krk_storage.c$(ObjectSuffix): krk_storage.c $(IntermediateDirectory)/krk_storage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_storage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_storage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_storage.c$(DependSuffix): krk_storage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_storage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_storage.c$(DependSuffix) -MM krk_storage.c

$(IntermediateDirectory)/krk_storage.c$(PreprocessSuffix): krk_storage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_storage.c$(PreprocessSuffix) krk_storage.c

$(IntermediateDirectory)/krk_umountdb.c$(ObjectSuffix): krk_umountdb.c $(IntermediateDirectory)/krk_umountdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/krk_umountdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/krk_umountdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/krk_umountdb.c$(DependSuffix): krk_umountdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/krk_umountdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/krk_umountdb.c$(DependSuffix) -MM krk_umountdb.c

$(IntermediateDirectory)/krk_umountdb.c$(PreprocessSuffix): krk_umountdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/krk_umountdb.c$(PreprocessSuffix) krk_umountdb.c

$(IntermediateDirectory)/q_processor.c$(ObjectSuffix): q_processor.c $(IntermediateDirectory)/q_processor.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/q_processor.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/q_processor.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/q_processor.c$(DependSuffix): q_processor.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/q_processor.c$(ObjectSuffix) -MF$(IntermediateDirectory)/q_processor.c$(DependSuffix) -MM q_processor.c

$(IntermediateDirectory)/q_processor.c$(PreprocessSuffix): q_processor.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/q_processor.c$(PreprocessSuffix) q_processor.c

$(IntermediateDirectory)/query_context.c$(ObjectSuffix): query_context.c $(IntermediateDirectory)/query_context.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/query_context.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/query_context.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/query_context.c$(DependSuffix): query_context.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/query_context.c$(ObjectSuffix) -MF$(IntermediateDirectory)/query_context.c$(DependSuffix) -MM query_context.c

$(IntermediateDirectory)/query_context.c$(PreprocessSuffix): query_context.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/query_context.c$(PreprocessSuffix) query_context.c

$(IntermediateDirectory)/randbyte.c$(ObjectSuffix): randbyte.c $(IntermediateDirectory)/randbyte.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/randbyte.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/randbyte.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/randbyte.c$(DependSuffix): randbyte.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/randbyte.c$(ObjectSuffix) -MF$(IntermediateDirectory)/randbyte.c$(DependSuffix) -MM randbyte.c

$(IntermediateDirectory)/randbyte.c$(PreprocessSuffix): randbyte.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/randbyte.c$(PreprocessSuffix) randbyte.c

$(IntermediateDirectory)/randint.c$(ObjectSuffix): randint.c $(IntermediateDirectory)/randint.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/randint.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/randint.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/randint.c$(DependSuffix): randint.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/randint.c$(ObjectSuffix) -MF$(IntermediateDirectory)/randint.c$(DependSuffix) -MM randint.c

$(IntermediateDirectory)/randint.c$(PreprocessSuffix): randint.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/randint.c$(PreprocessSuffix) randint.c

$(IntermediateDirectory)/sha1.c$(ObjectSuffix): sha1.c $(IntermediateDirectory)/sha1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/sha1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sha1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sha1.c$(DependSuffix): sha1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sha1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sha1.c$(DependSuffix) -MM sha1.c

$(IntermediateDirectory)/sha1.c$(PreprocessSuffix): sha1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sha1.c$(PreprocessSuffix) sha1.c

$(IntermediateDirectory)/storage_path.c$(ObjectSuffix): storage_path.c $(IntermediateDirectory)/storage_path.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/storage_path.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/storage_path.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/storage_path.c$(DependSuffix): storage_path.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/storage_path.c$(ObjectSuffix) -MF$(IntermediateDirectory)/storage_path.c$(DependSuffix) -MM storage_path.c

$(IntermediateDirectory)/storage_path.c$(PreprocessSuffix): storage_path.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/storage_path.c$(PreprocessSuffix) storage_path.c

$(IntermediateDirectory)/test.c$(ObjectSuffix): test.c $(IntermediateDirectory)/test.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/test.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test.c$(DependSuffix): test.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test.c$(ObjectSuffix) -MF$(IntermediateDirectory)/test.c$(DependSuffix) -MM test.c

$(IntermediateDirectory)/test.c$(PreprocessSuffix): test.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test.c$(PreprocessSuffix) test.c

$(IntermediateDirectory)/testdb.c$(ObjectSuffix): testdb.c $(IntermediateDirectory)/testdb.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/Users/skullybox/Desktop/kraken/src/testdb.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/testdb.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/testdb.c$(DependSuffix): testdb.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/testdb.c$(ObjectSuffix) -MF$(IntermediateDirectory)/testdb.c$(DependSuffix) -MM testdb.c

$(IntermediateDirectory)/testdb.c$(PreprocessSuffix): testdb.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/testdb.c$(PreprocessSuffix) testdb.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



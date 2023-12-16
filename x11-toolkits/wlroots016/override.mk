WLR_SUFFIX=	016

BUILD_DEPENDS:=	${BUILD_DEPENDS:S/wlroots/&${WLR_SUFFIX}/g}
LIB_DEPENDS:=	${LIB_DEPENDS:S/wlroots$/&${WLR_SUFFIX}/}

USES+=		localbase # -isystem
CONFIGURE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"
MAKE_ENV+=	PKG_CONFIG_PATH="${LOCALBASE}/wlroots${WLR_SUFFIX}/libdata/pkgconfig"

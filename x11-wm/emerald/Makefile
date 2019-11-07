# $FreeBSD$

PORTNAME=	emerald
PORTVERSION=	0.8.8
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	Emerald Window Decorator

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS:=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USES=		desktop-file-utils gl gmake gnome libtool pathfix \
		pkgconfig shared-mime-info tar:bzip2 xorg
USE_GL=		gl
USE_GNOME=	cairo gtk20 intltool libwnck pango
USE_XORG=	x11 xrender
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=		NLS
OPTIONS_DEFAULT=	NLS

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime gettext-tools

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h
	@${REINPLACE_CMD} '/^emerald_LDADD =/s/$$/ -lm/' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>

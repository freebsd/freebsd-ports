# $FreeBSD$

PORTNAME=	emerald
PORTVERSION=	0.8.4
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emerald Window Decorator

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:${PORTSDIR}/x11-wm/compiz
RUN_DEPENDS:=	${BUILD_DEPENDS}

INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_BZIP2=	yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig shared-mime-info
USE_GNOME=	gtk20 libwnck pango
USE_XORG=	xrender
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

# XXX - might want to change that
post-patch:
	@${REINPLACE_CMD} 's|icons/gnome|icons/hicolor|' ${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} -e 's|#define GDK_DISABLE_DEPRECATED||g' \
	    -e 's|#define GTK_DISABLE_DEPRECATED||g' ${WRKSRC}/include/emerald.h

.include <bsd.port.mk>

# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	gcompmgr
PORTVERSION=	0.21
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME interface to xcompmgr

RUN_DEPENDS=	xcompmgr:x11-wm/xcompmgr

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib -lX11
USES=		compiler:c++11-lang autoreconf gnome libtool pkgconfig xorg
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24
USE_XORG=	x11

DESKTOP_ENTRIES="gcompmgr" \
		"Configure window effects" \
		"" \
		"gcompmgr" \
		"DesktopSettings;Settings;GTK;" \
		true

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/INSTALL
	@${REINPLACE_CMD} -e '/^CXXFLAGS=""/d' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|connect(SigC::slot|connect(sigc::mem_fun|g ; \
		s|#include <sigc++\/compatibility\.h>||g' \
			${WRKSRC}/src/*.cc

.include <bsd.port.mk>

# New ports collection makefile for:	wmakerconf
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	wmakerconf
PORTVERSION=	2.9.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.starplot.org/wmakerconf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configuration tool for Window Maker

RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
.endif
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		wraster.4:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnometarget imlib
USE_PERL5=	yes
USE_XPM=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wmakerdir="${X11BASE}/share/WindowMaker"

MAN1=		mkpreview.1 wmakerconf.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	@${PERL} -pi -e 's|lynx wget|lynx fetch|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|: install-data-local|:|g' ${WRKSRC}/Makefile.in
.for file in WMWmakerconf.gettext WMWmakerconf
	@${PERL} -pi -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/data/${file}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/wmakerconf.desktop \
		${PREFIX}/share/gnome/apps/Settings

.include <bsd.port.mk>

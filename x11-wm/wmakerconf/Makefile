# New ports collection makefile for:	wmakerconf
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	wmakerconf
PORTVERSION=	2.11
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.starplot.org/wmakerconf/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configuration tool for Window Maker

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker
RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm
.if !exists(/usr/bin/bzip2)
RUN_DEPENDS+=	bunzip2:${PORTSDIR}/archivers/bzip2
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier gnometarget gtk20
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wmakerdir="${X11BASE}/share/WindowMaker"

MAN1=		mkpreview.1 wmakerconf.1

post-extract:
	@${FIND} ${WRKSRC} -name "*.gmo" -delete

pre-configure:
	@${PERL} -pi -e 's|lynx wget|lynx fetch|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|: install-data-local|:|g' ${WRKSRC}/Makefile.in
.for file in data/WMWmakerconf data/WMWmakerconf.gettext
	@${PERL} -pi -e 's|/usr/local/share|${LOCALBASE}|g ; \
		 s|/usr/share|${X11BASE}|g' ${WRKSRC}/${file}
.endfor
.for file in data/po/ja.po po/ja.po
	@${PERL} -pi -e 's|JISX-0208-1983-0|euc-jp|g' ${WRKSRC}/${file}
.endfor

post-install:
	@${MKDIR} ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/wmakerconf.desktop \
		${PREFIX}/share/gnome/applications

.include <bsd.port.mk>

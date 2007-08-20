# New ports collection makefile for:	wmakerconf
# Date Created:				14 August 1999
# Whom:					Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#    $MCom: ports/x11-wm/wmakerconf/Makefile,v 1.2 2006/10/05 07:31:44 mezz Exp $
#

PORTNAME=	wmakerconf
PORTVERSION=	2.12
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A configuration tool for Window Maker

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker
RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XLIB=	yes
USE_GNOME=	gnometarget gtk20
USE_PERL5=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wmakerdataprefix="${LOCALBASE}/share" \
		--with-wmakeretcprefix="${LOCALBASE}/share"

MAN1=		mkpreview.1 wmakerconf.1

post-extract:
	@${FIND} ${WRKSRC} -name "*.gmo" -delete

pre-configure:
	@${REINPLACE_CMD} -e 's|lynx wget|lynx fetch|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/chmod 0/d' ${WRKSRC}/Makefile.in
.for file in data/WMWmakerconf data/WMWmakerconf.gettext
	@${REINPLACE_CMD} -e 's|/usr/local/share|${LOCALBASE}|g ; \
		 s|/usr/share|${X11BASE}|g' ${WRKSRC}/${file}
.endfor
.for file in data/po/ja.po po/ja.po
	@${REINPLACE_CMD} -e 's|JISX-0208-1983-0|euc-jp|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>

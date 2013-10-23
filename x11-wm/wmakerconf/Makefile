# Created by: Dominik Rothert <dr@domix.de>
# $FreeBSD$
#    $MCom: ports/x11-wm/wmakerconf/Makefile,v 1.2 2006/10/05 07:31:44 mezz Exp $

PORTNAME=	wmakerconf
PORTVERSION=	2.12
PORTREVISION=	7
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration tool for Window Maker

LICENSE=	GPLv2

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker
RUN_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gtk20
USES=		gettext pkgconfig perl5 gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wmakerdataprefix="${LOCALBASE}/share" \
		--with-wmakeretcprefix="${LOCALBASE}/share"

MAN1=		mkpreview.1 wmakerconf.1

NO_STAGE=	yes
post-extract:
	@${FIND} ${WRKSRC} -name "*.gmo" -delete

post-patch:
	@${REINPLACE_CMD} -e 's|lynx wget|lynx fetch|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/chmod 0/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E '/\/usr\/share/d; \
			      s|/usr/local|${LOCALBASE}|g ; \
		 	      s|/usr/X11R6|${LOCALBASE}|g; \
			      s|(share/pixmaps.*),|\1|g' \
		${WRKSRC}/data/WMWmakerconf*
.for file in data/po/ja.po po/ja.po
	@${REINPLACE_CMD} -e 's|JISX-0208-1983-0|euc-jp|g' ${WRKSRC}/${file}
.endfor
	@${FIND} ${WRKSRC}/src -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		'/WMWritePropListToFile/s|,[[:space:]]YES||g'

.include <bsd.port.mk>

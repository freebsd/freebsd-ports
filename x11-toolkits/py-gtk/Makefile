# New ports collection makefile for:	pygtk
# Version required:	0.5.2
# Date created:		30 May 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1998/09/25 09:52:44 asami Exp $
#

DISTNAME=	pygtk-0.5.2
PKGNAME=	py-gtk-0.5.2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/ \
		ftp://ftp.gimp.org/pub/gtk/python/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gtk/python/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/python/ \
		ftp://stef.u-picardie.fr/mirror/ftp.gimp.org/gtk/python/

MAINTAINER=	ports@FreeBSD.ORG


OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} >= 300000
BROKEN=         python
.endif

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
LIB_DEPENDS=	Imlib.1:${PORTSDIR}/graphics/imlib
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk-config=${X11BASE}/bin/gtk11-config
ALL_TARGET=	sharedmods
MAKE_FLAGS=	OPT="${CFLAGS}"

post-install:
	@${MKDIR} ${PREFIX}/share/examples/pygtk
	@(cd ${WRKSRC}/examples; tar cf - *) | \
		(cd ${PREFIX}/share/examples/pygtk; tar xf -)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pygtk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pygtk
.endif

.include <bsd.port.mk>

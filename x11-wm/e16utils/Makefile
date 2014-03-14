# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	e16utils
PORTVERSION=	0.16
PORTREVISION=	12
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	SF/enlightenment/e16menuedit/e16menuedit:src1 \
		SF/enlightenment/e16keyedit/0.7:src2
DISTFILES=	e16menuedit-0.1.tar.gz:src1 \
		e16keyedit-0.7.tar.gz:src2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standalone menu and keybinding editors for enlightenment 0.16

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_GNOME=	imlib gtk20
USES=		pkgconfig

SUB_STUBS=	e16menuedit-0.1 e16keyedit-0.7

PLIST_FILES=	bin/e16menuedit \
		bin/e16keyedit

NO_STAGE=	yes
do-patch:
.for i in ${SUB_STUBS}
	if [ -f "${PATCHDIR}/patch-${i}" ]; then \
		cd ${WRKDIR}/${i} ; ${PATCH} -s < ${PATCHDIR}/patch-${i}; \
	fi
.endfor

do-configure:
.for i in ${SUB_STUBS}
	if [ -f "${WRKDIR}/${i}/${CONFIGURE_SCRIPT}" ]; then \
		cd ${WRKDIR}/${i} && ${SETENV} ${CONFIGURE_ENV} \
			./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	fi
.endfor

do-build:
.for i in ${SUB_STUBS}
	@cd ${WRKDIR}/${i} && ${SETENV} ${MAKE_ENV} ${MAKE} all
.endfor

do-install:
.for i in ${SUB_STUBS}
	@cd ${WRKDIR}/${i} && \
	${INSTALL_PROGRAM} `${ECHO_CMD} '${i}' | ${SED} -e 's,-\(.*\),,'` \
	${PREFIX}/bin
.endfor

.include <bsd.port.mk>
